EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Elektronika 1 Pulsar replacement module"
Date ""
Rev "1.2"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:Crystal Y1
U 1 1 607D0BEB
P 2750 3150
F 0 "Y1" V 2700 2950 50  0000 C CNN
F 1 "32.768kHz" V 2800 2800 50  0000 C CNN
F 2 "Crystal:Crystal_SMD_0603-2Pin_6.0x3.5mm_HandSoldering" H 2750 3150 50  0001 C CNN
F 3 "~" H 2750 3150 50  0001 C CNN
	1    2750 3150
	0    1    -1   0   
$EndComp
$Comp
L power:GND #PWR06
U 1 1 607D64F4
P 7950 3850
F 0 "#PWR06" H 7950 3600 50  0001 C CNN
F 1 "GND" H 7955 3677 50  0000 C CNN
F 2 "" H 7950 3850 50  0001 C CNN
F 3 "" H 7950 3850 50  0001 C CNN
	1    7950 3850
	1    0    0    -1  
$EndComp
Text GLabel 8150 3100 2    50   Input ~ 0
RST_SBWTDIO
Text GLabel 9650 1100 0    50   Input ~ 0
TST_SBWTCK
Text GLabel 9650 1200 0    50   Input ~ 0
RST_SBWTDIO
$Comp
L power:+3V0 #PWR07
U 1 1 6080C75D
P 8950 1500
F 0 "#PWR07" H 8950 1350 50  0001 C CNN
F 1 "+3V0" H 8965 1673 50  0000 C CNN
F 2 "" H 8950 1500 50  0001 C CNN
F 3 "" H 8950 1500 50  0001 C CNN
	1    8950 1500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 6080F947
P 8950 1700
F 0 "#PWR08" H 8950 1450 50  0001 C CNN
F 1 "GND" H 8955 1527 50  0000 C CNN
F 2 "" H 8950 1700 50  0001 C CNN
F 3 "" H 8950 1700 50  0001 C CNN
	1    8950 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8950 1500 9800 1500
Wire Wire Line
	9650 1400 9800 1400
Wire Wire Line
	9650 1300 9800 1300
Text GLabel 8150 2000 2    50   Input ~ 0
TST_SBWTCK
$Comp
L Mechanical:MountingHole_Pad H2
U 1 1 60809AD9
P 2600 1950
F 0 "H2" H 2600 2237 50  0000 C CNN
F 1 "SW2" H 2600 2146 50  0000 C CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_DIN965_Pad_TopBottom" H 2600 1950 50  0001 C CNN
F 3 "~" H 2600 1950 50  0001 C CNN
	1    2600 1950
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H4
U 1 1 6080B044
P 2400 1950
F 0 "H4" H 2400 2237 50  0000 C CNN
F 1 "SW3" H 2400 2146 50  0000 C CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_DIN965_Pad_TopBottom" H 2400 1950 50  0001 C CNN
F 3 "~" H 2400 1950 50  0001 C CNN
	1    2400 1950
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H1
U 1 1 6080B314
P 2800 1950
F 0 "H1" H 2800 2237 50  0000 C CNN
F 1 "SW1" H 2800 2146 50  0000 C CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_DIN965_Pad_TopBottom" H 2800 1950 50  0001 C CNN
F 3 "~" H 2800 1950 50  0001 C CNN
	1    2800 1950
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H4
U 1 1 6080B61D
P 2200 1950
F 0 "H4" H 2200 2237 50  0000 C CNN
F 1 "SW4" H 2200 2146 50  0000 C CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_DIN965_Pad_TopBottom" H 2200 1950 50  0001 C CNN
F 3 "~" H 2200 1950 50  0001 C CNN
	1    2200 1950
	1    0    0    -1  
$EndComp
$Comp
L power:+3V0 #PWR05
U 1 1 60816301
P 3550 2000
F 0 "#PWR05" H 3550 1850 50  0001 C CNN
F 1 "+3V0" H 3565 2173 50  0000 C CNN
F 2 "" H 3550 2000 50  0001 C CNN
F 3 "" H 3550 2000 50  0001 C CNN
	1    3550 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 2000 3750 2000
Wire Wire Line
	2750 3300 2750 3350
Wire Wire Line
	2750 3350 3050 3350
Wire Wire Line
	2750 3000 2750 2950
Wire Wire Line
	2750 2950 3050 2950
$Comp
L Device:C_Small C2
U 1 1 60869818
P 3150 2950
F 0 "C2" V 2921 2950 50  0000 C CNN
F 1 "12pF" V 3012 2950 50  0000 C CNN
F 2 "Capacitor_SMD:C_0402_1005Metric_Pad0.74x0.62mm_HandSolder" H 3150 2950 50  0001 C CNN
F 3 "~" H 3150 2950 50  0001 C CNN
	1    3150 2950
	0    1    -1   0   
$EndComp
$Comp
L Device:C_Small C3
U 1 1 60869C35
P 3150 3350
F 0 "C3" V 2921 3350 50  0000 C CNN
F 1 "12pF" V 3012 3350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0402_1005Metric_Pad0.74x0.62mm_HandSolder" H 3150 3350 50  0001 C CNN
F 3 "~" H 3150 3350 50  0001 C CNN
	1    3150 3350
	0    1    -1   0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H5
U 1 1 609D6435
P 2000 1950
F 0 "H5" H 2000 2237 50  0000 C CNN
F 1 "SW5" H 2000 2146 50  0000 C CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_DIN965_Pad_TopBottom" H 2000 1950 50  0001 C CNN
F 3 "~" H 2000 1950 50  0001 C CNN
	1    2000 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 2050 2600 2300
Wire Wire Line
	2800 2050 2800 2200
Wire Wire Line
	2000 2800 3750 2800
Wire Wire Line
	2600 2300 3750 2300
Wire Wire Line
	2800 2200 3750 2200
Wire Wire Line
	8950 1700 9800 1700
Text GLabel 3550 2400 0    50   Input ~ 0
I2C_SDA
Text GLabel 3550 2500 0    50   Input ~ 0
I2C_SLC
NoConn ~ 4750 6700
NoConn ~ 4750 6600
NoConn ~ 4750 6400
NoConn ~ 4750 6300
NoConn ~ 4750 6200
NoConn ~ 4750 6100
Wire Wire Line
	7350 5400 7200 5400
Wire Wire Line
	7350 6000 7350 5400
Wire Wire Line
	4750 6000 7350 6000
Wire Wire Line
	7450 5300 7200 5300
Wire Wire Line
	7450 5900 7450 5300
Wire Wire Line
	4750 5900 7450 5900
Wire Wire Line
	7550 5200 7200 5200
Wire Wire Line
	7550 5800 7550 5200
Wire Wire Line
	4750 5800 7550 5800
Wire Wire Line
	7650 5100 7200 5100
Wire Wire Line
	7650 5700 7650 5100
Wire Wire Line
	4750 5700 7650 5700
Wire Wire Line
	4900 5400 5000 5400
Wire Wire Line
	4900 5500 4900 5400
Wire Wire Line
	4750 5500 4900 5500
Wire Wire Line
	4750 5300 5000 5300
Wire Wire Line
	4750 5200 5000 5200
Wire Wire Line
	4750 5100 5000 5100
Wire Wire Line
	4750 5000 5000 5000
Wire Wire Line
	4750 4900 5000 4900
Wire Wire Line
	4750 4800 5000 4800
Wire Wire Line
	4750 4700 5000 4700
$Comp
L Interface_Expansion:AS1115-BQFT U2
U 1 1 60A4EE5A
P 4150 5700
F 0 "U2" H 4100 5700 50  0000 C CNN
F 1 "AS1115-BQFT" H 4100 5600 50  0000 C CNN
F 2 "Package_DFN_QFN:TQFN-24-1EP_4x4mm_P0.5mm_EP2.8x2.8mm_PullBack_ThermalVias" H 4150 5700 50  0001 C CNN
F 3 "https://ams.com/documents/20143/36005/AS1115_DS000206_1-00.pdf/3d3e6d35-b184-1329-adf9-2d769eb2404f" H 4150 5700 50  0001 C CNN
	1    4150 5700
	1    0    0    -1  
$EndComp
$Comp
L hp-5082-7414:HP-5082-7414 DISP1
U 1 1 6081B38E
P 6100 5000
F 0 "DISP1" H 6100 5400 50  0000 C CNN
F 1 "HP-5082-7414" H 6100 4600 50  0000 C CNN
F 2 "Package_DIP:DIP-12_W7.62mm_Socket_LongPads" H 6100 4400 50  0001 C CNN
F 3 "https://www.datasheets360.com/pdf/-6482069211030632702" H 5670 5030 50  0001 C CNN
	1    6100 5000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60A75165
P 4150 7050
F 0 "#PWR?" H 4150 6800 50  0001 C CNN
F 1 "GND" H 4155 6877 50  0000 C CNN
F 2 "" H 4150 7050 50  0001 C CNN
F 3 "" H 4150 7050 50  0001 C CNN
	1    4150 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 6900 4150 7050
Wire Wire Line
	4050 6900 4150 6900
Connection ~ 4150 6900
$Comp
L power:+3V0 #PWR?
U 1 1 60A7834B
P 4150 4350
F 0 "#PWR?" H 4150 4200 50  0001 C CNN
F 1 "+3V0" H 4165 4523 50  0000 C CNN
F 2 "" H 4150 4350 50  0001 C CNN
F 3 "" H 4150 4350 50  0001 C CNN
	1    4150 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 4350 4150 4500
NoConn ~ 7950 2200
NoConn ~ 7950 2300
NoConn ~ 7950 2400
NoConn ~ 3750 2900
Connection ~ 2700 5400
Wire Wire Line
	2700 5050 2700 5400
Wire Wire Line
	2550 5400 2700 5400
Wire Wire Line
	2550 5300 2950 5300
Connection ~ 2950 4800
Wire Wire Line
	2700 4800 2950 4800
Wire Wire Line
	3200 4800 2950 4800
Wire Wire Line
	2700 4800 2700 4700
Connection ~ 2700 4800
Wire Wire Line
	2950 4850 2950 4800
Wire Wire Line
	2700 4850 2700 4800
$Comp
L power:+3V0 #PWR?
U 1 1 60A97EF3
P 2700 4700
F 0 "#PWR?" H 2700 4550 50  0001 C CNN
F 1 "+3V0" H 2715 4873 50  0000 C CNN
F 2 "" H 2700 4700 50  0001 C CNN
F 3 "" H 2700 4700 50  0001 C CNN
	1    2700 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R1
U 1 1 60A8F4E5
P 2700 4950
F 0 "R1" H 2750 5000 50  0000 L CNN
F 1 "10k" H 2750 4900 50  0000 L CNN
F 2 "" H 2700 4950 50  0001 C CNN
F 3 "~" H 2700 4950 50  0001 C CNN
	1    2700 4950
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R2
U 1 1 60A8D2FD
P 2950 4950
F 0 "R2" H 3009 4996 50  0000 L CNN
F 1 "10k" H 3009 4905 50  0000 L CNN
F 2 "" H 2950 4950 50  0001 C CNN
F 3 "~" H 2950 4950 50  0001 C CNN
	1    2950 4950
	1    0    0    -1  
$EndComp
Text GLabel 2550 5300 0    50   Input ~ 0
I2C_SLC
Text GLabel 2550 5400 0    50   Input ~ 0
I2C_SDA
Wire Wire Line
	3200 5050 3200 5100
Wire Wire Line
	3200 4850 3200 4800
Wire Wire Line
	3200 5100 3550 5100
$Comp
L Device:R_Small R3
U 1 1 60AA50D6
P 3200 4950
F 0 "R3" H 3259 4996 50  0000 L CNN
F 1 "40k" H 3259 4905 50  0000 L CNN
F 2 "" H 3200 4950 50  0001 C CNN
F 3 "~" H 3200 4950 50  0001 C CNN
	1    3200 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 5400 3550 5400
Wire Wire Line
	2950 5050 2950 5300
Connection ~ 2950 5300
Wire Wire Line
	2950 5300 3550 5300
NoConn ~ 3750 3300
$Comp
L Connector_Generic:Conn_01x07 J1
U 1 1 6080A23D
P 10000 1400
F 0 "J1" H 10080 1442 50  0000 L CNN
F 1 "eZ-FET" H 9750 1850 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x07_P2.54mm_Vertical" H 10000 1400 50  0001 C CNN
F 3 "~" H 10000 1400 50  0001 C CNN
	1    10000 1400
	1    0    0    -1  
$EndComp
Text GLabel 9650 1300 0    50   Input ~ 0
BCLUART_TXD
NoConn ~ 9800 1600
Text GLabel 9650 1400 0    50   Input ~ 0
BCLUART_RXD
Wire Wire Line
	9650 1100 9800 1100
Wire Wire Line
	9650 1200 9800 1200
Wire Wire Line
	2400 2600 3750 2600
Wire Wire Line
	2200 2700 3750 2700
Wire Wire Line
	2000 2050 2000 2800
Wire Wire Line
	2200 2050 2200 2700
Wire Wire Line
	2400 2050 2400 2600
Wire Wire Line
	3550 2400 3750 2400
Wire Wire Line
	3550 2500 3750 2500
NoConn ~ 3750 3400
NoConn ~ 3750 3500
NoConn ~ 3750 3800
Text GLabel 3550 3700 0    50   Input ~ 0
BCLUART_TXD
Text GLabel 3550 3600 0    50   Input ~ 0
BCLUART_RXD
NoConn ~ 3550 5600
Wire Wire Line
	3250 2950 3450 2950
Wire Wire Line
	3450 2950 3450 3100
Wire Wire Line
	3250 3350 3450 3350
Wire Wire Line
	3450 3350 3450 3200
Wire Wire Line
	3450 3100 3750 3100
Wire Wire Line
	3450 3200 3750 3200
Wire Wire Line
	3550 3600 3750 3600
Wire Wire Line
	3550 3700 3750 3700
Wire Wire Line
	7950 2000 8150 2000
Wire Wire Line
	8150 3100 7950 3100
$Comp
L MSP430FR2433IRGET:MSP430FR2433IRGET U1
U 1 1 60A5CED8
P 5850 2900
F 0 "U1" H 5850 3900 60  0000 C CNN
F 1 "MSP430FR2433IRGET" H 5850 3750 60  0000 C CNN
F 2 "RGE0024G" H 5850 2840 60  0001 C CNN
F 3 "" H 5850 2900 60  0000 C CNN
	1    5850 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 3800 7950 3850
Wire Wire Line
	1150 850  1550 850 
Wire Wire Line
	1150 1150 1550 1150
Wire Wire Line
	1950 1150 1950 1100
Wire Wire Line
	1950 850  1950 900 
$Comp
L Device:CP_Small C1
U 1 1 60A6E5A2
P 1550 1000
F 0 "C1" H 1638 1046 50  0000 L CNN
F 1 "10uF*" H 1638 955 50  0000 L CNN
F 2 "" H 1550 1000 50  0001 C CNN
F 3 "~" H 1550 1000 50  0001 C CNN
	1    1550 1000
	1    0    0    -1  
$EndComp
Connection ~ 1150 1150
Connection ~ 1150 850 
$Comp
L Device:C_Small C2
U 1 1 6081B29D
P 1950 1000
F 0 "C2" H 2042 1046 50  0000 L CNN
F 1 "100nF*" H 2042 955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1950 1000 50  0001 C CNN
F 3 "~" H 1950 1000 50  0001 C CNN
	1    1950 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 800  1150 850 
Wire Wire Line
	1150 1150 1150 1200
$Comp
L power:+3V0 #PWR01
U 1 1 607D8AD3
P 1150 800
F 0 "#PWR01" H 1150 650 50  0001 C CNN
F 1 "+3V0" H 1165 973 50  0000 C CNN
F 2 "" H 1150 800 50  0001 C CNN
F 3 "" H 1150 800 50  0001 C CNN
	1    1150 800 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 607D5D9F
P 1150 1200
F 0 "#PWR02" H 1150 950 50  0001 C CNN
F 1 "GND" H 1155 1027 50  0000 C CNN
F 2 "" H 1150 1200 50  0001 C CNN
F 3 "" H 1150 1200 50  0001 C CNN
	1    1150 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT1
U 1 1 607D39F2
P 1150 1050
F 0 "BT1" H 900 1200 50  0000 L CNN
F 1 "3V CR2032" H 600 1050 50  0000 L CNN
F 2 "Battery:BatteryHolder_Keystone_3002_1x2032" V 1150 1110 50  0001 C CNN
F 3 "~" V 1150 1110 50  0001 C CNN
	1    1150 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 850  1550 900 
Connection ~ 1550 850 
Wire Wire Line
	1550 850  1950 850 
Wire Wire Line
	1550 1100 1550 1150
Connection ~ 1550 1150
Wire Wire Line
	1550 1150 1950 1150
Wire Notes Line
	550  1450 550  550 
Text Notes 1850 1400 0    50   ~ 0
* Low ESR
Wire Notes Line
	2350 550  2350 1450
Wire Notes Line
	550  550  2350 550 
Wire Notes Line
	550  1450 2350 1450
Wire Wire Line
	7950 3500 7950 3600
Connection ~ 7950 3800
Connection ~ 7950 3600
Wire Wire Line
	7950 3600 7950 3800
Text Notes 7050 6900 0    118  ~ 0
Note: No battery inserted while programming.
$EndSCHEMATC