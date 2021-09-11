#include "display.h"
#include "eusci_b_i2c.h"
#include "pmm.h"

#define CMD_DIGIT_BASE 0x01

#define CMD_DECODE_MODE 0x09
#define ARG_DECODE_MODE_NONE 0x00

#define CMD_GLOBAL_INTENSITY 0x0A
#define ARG_GLOBAL_INTENSITY_MIN 0x00
#define ARG_GLOBAL_INTENSITY_NOR 0x07
#define ARG_GLOBAL_INTENSITY_MAX 0x0E

#define CMD_SCAN_LIMIT 0x0B
#define ARG_SCAN_LIMIT_1_DIGITS 0x00
#define ARG_SCAN_LIMIT_2_DIGITS 0x01
#define ARG_SCAN_LIMIT_3_DIGITS 0x02
#define ARG_SCAN_LIMIT_4_DIGITS 0x03
#define ARG_SCAN_LIMIT_5_DIGITS 0x04
#define ARG_SCAN_LIMIT_6_DIGITS 0x05
#define ARG_SCAN_LIMIT_7_DIGITS 0x06
#define ARG_SCAN_LIMIT_8_DIGITS 0x07

#define CMD_POWER 0x0C
#define ARG_POWER_OFF 0x00
#define ARG_POWER_ON 0x01

#pragma PERSISTENT(current_intensity)

uint8_t current_intensity = ARG_GLOBAL_INTENSITY_NOR;

uint8_t screen[] = { 0, 0, 0, 0 };

uint8_t Display_get_screen(uint8_t **screen_ptr)
{
    *screen_ptr = &screen;
    return sizeof(screen);
}

void Display_send(uint8_t command, uint8_t data)
{
    EUSCI_B_I2C_setMode(I2C_BASE, EUSCI_B_I2C_TRANSMIT_MODE);
    if (EUSCI_B_I2C_masterSendMultiByteStartWithTimeout(I2C_BASE, command, I2C_TIMEOUT) != STATUS_SUCCESS) {
        PMM_trigBOR();
    }
    if (EUSCI_B_I2C_masterSendMultiByteFinishWithTimeout(I2C_BASE, data, I2C_TIMEOUT) != STATUS_SUCCESS) {
        PMM_trigBOR();
    }
    uint32_t timeout = I2C_TIMEOUT;
    while (EUSCI_B_I2C_isBusBusy(I2C_BASE) && --timeout) ;
    if (timeout == 0) {
        PMM_trigBOR();
    }
}

void Display_update_screen(void)
{
    for (uint8_t i = 0; i < sizeof(screen); i++) {
        Display_send(CMD_DIGIT_BASE + i, screen[i]);
    }
}

void Display_fill(uint8_t pattern)
{
    for (uint8_t i = 0; i < sizeof(screen); i++) {
        Display_send(CMD_DIGIT_BASE + i, pattern);
    }
}


void Display_clear(void)
{
    Display_fill(0);
}

void Display_init(void)
{
    EUSCI_B_I2C_disable(I2C_BASE);
    EUSCI_B_I2C_initMasterParam parameters = {
       .selectClockSource = EUSCI_B_I2C_CLOCKSOURCE_MODCLK,
       .i2cClk = CONFIG_OSCMOD_HZ,
       .dataRate = EUSCI_B_I2C_SET_DATA_RATE_100KBPS,
       .byteCounterThreshold = 0,
       .autoSTOPGeneration = EUSCI_B_I2C_NO_AUTO_STOP,
    };

    EUSCI_B_I2C_initMaster(I2C_BASE, &parameters);
    EUSCI_B_I2C_setSlaveAddress(I2C_BASE, AS1115_SLAVE_ADDRESS);
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P1, GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);
    EUSCI_B_I2C_enable(I2C_BASE);
    Display_send(CMD_DECODE_MODE, ARG_DECODE_MODE_NONE);
    Display_send(CMD_SCAN_LIMIT, ARG_SCAN_LIMIT_4_DIGITS);
    Display_send_intensity();

    Display_start(CLEAR);

    // Turn on all segments
    Display_fill(0xFF);
    for (uint32_t x=0;x<0x18000;x++) {
        __no_operation();
    }
    // Display USSr
    screen[0] = SEG_F | SEG_E | SEG_D | SEG_C | SEG_B;
    screen[1] = SEG_A | SEG_F | SEG_G | SEG_C | SEG_D;
    screen[2] = SEG_A | SEG_F | SEG_G | SEG_C | SEG_D;
    screen[3] = SEG_E | SEG_G;
    Display_update_screen();
    for (uint32_t x=0;x<0x30000;x++) {
        __no_operation();
    }
    // Display EL-1
    screen[0] = SEG_A | SEG_F | SEG_G | SEG_E | SEG_D;
    screen[1] = SEG_F | SEG_E | SEG_D;
    screen[2] = SEG_G;
    screen[3] = SEG_B | SEG_C;
    Display_update_screen();
    for (uint32_t x=0;x<0x30000;x++) {
        __no_operation();
    }

    Display_stop();
}


void Display_start(bool clear)
{
    EUSCI_B_I2C_enable(I2C_BASE);
    if (clear) {
        Display_clear();
    }
    Display_send(CMD_POWER, ARG_POWER_ON);
}

void Display_stop(void)
{
    Display_send(CMD_POWER, ARG_POWER_OFF);
    EUSCI_B_I2C_disable(I2C_BASE);
}

void Display_save_intensity(uint8_t new_intensity)
{
    current_intensity = new_intensity;
    FRAMCtl_write8(&new_intensity, &current_intensity, sizeof(uint8_t));
}

void Display_add_intensity(uint8_t delta)
{
    unsigned short state;
    ENTER_CRITICAL_SECTION(state);
    Display_save_intensity((current_intensity + delta) & 0x0F);
    EXIT_CRITICAL_SECTION(state);
    Display_send_intensity();
}

void Display_send_intensity()
{
    Display_send(CMD_GLOBAL_INTENSITY, current_intensity); // Between 0 and 0x0f (actually 0x0e ?)
}
