#include "display.h"
#include "eusci_b_i2c.h"

#define CMD_DIGIT_BASE 0x00

#define CMD_DECODE_MODE 0x09
#define ARG_DECODE_MODE_NONE 0x00

#define CMD_GLOBAL_INTENSITY 0x0A
#define ARG_GLOBAL_INTENSITY_MIN 0x00
#define ARG_GLOBAL_INTENSITY_MAX 0x0E

#define CMD_SCAN_LIMIT 0x0B
#define ARG_SCAN_LIMIT_2_DIGITS 0x01
#define ARG_SCAN_LIMIT_4_DIGITS 0x03

#define CMD_POWER 0x0C
#define ARG_POWER_OFF 0x00
#define ARG_POWER_ON 0x01

uint8_t screen[] = { 0, 0, 0, 0 };

void Display_send(uint8_t command, uint8_t data)
{
    EUSCI_B_I2C_setMode(I2C_BASE, EUSCI_B_I2C_TRANSMIT_MODE);
    EUSCI_B_I2C_masterSendStart(I2C_BASE);
    EUSCI_B_I2C_masterSendMultiByteNext(I2C_BASE, command);
    EUSCI_B_I2C_masterSendMultiByteNext(I2C_BASE, data);
    EUSCI_B_I2C_masterSendMultiByteStop(I2C_BASE);
    while (EUSCI_B_I2C_isBusBusy(I2C_BASE)) {
        __no_operation();
    }
}

void Display_update(uint8_t *data)
{
    memcpy(&screen, data, sizeof(screen));
    for (uint8_t i = 0; i < sizeof(screen); i++) {
        Display_send(CMD_DIGIT_BASE + i, screen[i]);
    }
}

void Display_init(void)
{
    EUSCI_B_I2C_initMasterParam parameters = {
       .selectClockSource = EUSCI_B_I2C_CLOCKSOURCE_MODCLK,
       .i2cClk = CS_getMCLK(),
       .dataRate = EUSCI_B_I2C_SET_DATA_RATE_100KBPS,
       .byteCounterThreshold = 0,
       .autoSTOPGeneration = EUSCI_B_I2C_NO_AUTO_STOP,
    };

    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN2 + GPIO_PIN3, GPIO_SECONDARY_MODULE_FUNCTION);
    EUSCI_B_I2C_initMaster(I2C_BASE, &parameters);
    EUSCI_B_I2C_setSlaveAddress(I2C_BASE, AS1115_SLAVE_ADDRESS);
    Display_send(CMD_DECODE_MODE, ARG_DECODE_MODE_NONE);
    Display_send(CMD_SCAN_LIMIT, ARG_SCAN_LIMIT_4_DIGITS);
    Display_set_intensity(ARG_GLOBAL_INTENSITY_MIN);
}

void Display_set_intensity(uint8_t intensity)
{
    Display_send(CMD_GLOBAL_INTENSITY, intensity); // Between 0 and 0x0f
}

void Display_start(void)
{
    EUSCI_B_I2C_enable(I2C_BASE);
    Display_send(CMD_POWER, ARG_POWER_ON);
}

void Display_stop(void)
{
    Display_send(CMD_POWER, ARG_POWER_OFF);
    EUSCI_B_I2C_disable(I2C_BASE);
}