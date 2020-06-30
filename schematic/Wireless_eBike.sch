EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:Dongle
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L BSS138 Q?
U 1 1 5EEB0905
P 9400 3350
F 0 "Q?" H 9600 3425 50  0000 L CNN
F 1 "BSS100" H 9600 3350 50  0000 L CNN
F 2 "~" H 9600 3275 50  0000 L CIN
F 3 "" H 9400 3350 50  0000 L CNN
	1    9400 3350
	1    0    0    -1  
$EndComp
$Comp
L BTS4140N U?
U 1 1 5EEB0A4F
P 9600 2400
F 0 "U?" V 9600 2100 60  0000 C CNN
F 1 "BTS4140N" V 9750 2150 60  0000 C CNN
F 2 "" H 9000 2450 60  0000 C CNN
F 3 "" H 9000 2450 60  0000 C CNN
	1    9600 2400
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5EEB0D77
P 9500 3650
F 0 "#PWR?" H 9500 3400 50  0001 C CNN
F 1 "GND" H 9500 3500 50  0000 C CNN
F 2 "" H 9500 3650 50  0000 C CNN
F 3 "" H 9500 3650 50  0000 C CNN
	1    9500 3650
	1    0    0    -1  
$EndComp
$Comp
L nRF52840 U?
U 1 1 5EEB15B7
P 7750 3400
F 0 "U?" H 7750 3450 60  0000 C CNN
F 1 "nRF52840" H 7750 2850 60  0000 C CNN
F 2 "" H 7750 3400 60  0000 C CNN
F 3 "" H 7750 3400 60  0000 C CNN
	1    7750 3400
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P?
U 1 1 5EEB15DE
P 8850 3150
F 0 "P?" H 8850 3400 50  0000 C CNN
F 1 "Flashing" V 8950 3150 50  0000 C CNN
F 2 "" H 8850 3150 50  0000 C CNN
F 3 "" H 8850 3150 50  0000 C CNN
	1    8850 3150
	1    0    0    -1  
$EndComp
$Comp
L Generic_DC-DC U?
U 1 1 5EEB1756
P 5800 3000
F 0 "U?" H 5800 3000 60  0000 C CNN
F 1 "Generic_DC-DC" H 5800 3250 60  0000 C CNN
F 2 "" H 5750 3000 60  0000 C CNN
F 3 "" H 5750 3000 60  0000 C CNN
	1    5800 3000
	1    0    0    -1  
$EndComp
NoConn ~ 7200 2900
NoConn ~ 8300 2900
$Comp
L 6-Way_Higo K?
U 1 1 5EEB225F
P 2350 3500
F 0 "K?" H 2350 3250 60  0000 C CNN
F 1 "6-Way_Higo" H 2300 4050 60  0000 C CNN
F 2 "" H 2350 3500 60  0000 C CNN
F 3 "" H 2350 3500 60  0000 C CNN
	1    2350 3500
	1    0    0    -1  
$EndComp
$Comp
L 8-Way_Higo K?
U 1 1 5EEB22D5
P 2300 2100
F 0 "K?" H 2150 1750 60  0000 C CNN
F 1 "8-Way_Higo" H 2150 2750 60  0000 C CNN
F 2 "" H 2300 2100 60  0000 C CNN
F 3 "" H 2300 2100 60  0000 C CNN
	1    2300 2100
	1    0    0    -1  
$EndComp
Text Notes 1350 2750 0    60   ~ 0
  NOTE!!! Wire colouring and pin numbers\nmay change! Always check with a meter first.
Text GLabel 3200 1700 2    57   Output ~ 0
V.Battery
Text GLabel 3200 1800 2    57   Input ~ 0
TSDZ2_Vin
Text GLabel 3200 2100 2    57   Input ~ 0
TSDZ2_Brake_Input
Text GLabel 3200 2300 2    57   Output ~ 0
TSDZ2_Tx
Text GLabel 3200 1900 2    57   Input ~ 0
TSDZ2_Rx
NoConn ~ 2900 2200
Text GLabel 3200 3400 2    57   Output ~ 0
V.Battery
Text GLabel 3200 3600 2    57   Input ~ 0
TSDZ2_Vin
Text GLabel 3200 3200 2    57   Input ~ 0
TSDZ2_Brake_Input
Text GLabel 3200 3500 2    57   Output ~ 0
TSDZ2_Tx
Text GLabel 3200 3300 2    57   Input ~ 0
TSDZ2_Rx
$Comp
L GND #PWR?
U 1 1 5EEB2BD7
P 6400 3200
F 0 "#PWR?" H 6400 2950 50  0001 C CNN
F 1 "GND" H 6400 3050 50  0000 C CNN
F 2 "" H 6400 3200 50  0000 C CNN
F 3 "" H 6400 3200 50  0000 C CNN
	1    6400 3200
	1    0    0    -1  
$EndComp
Text GLabel 4900 2900 0    57   Input ~ 0
V.Battery
Text Notes 9500 3150 0    60   ~ 0
Floating = OFF\nGND = On
Text GLabel 10250 2850 2    57   Output ~ 0
TSDZ2_Vin
Text GLabel 7000 3400 0    57   Output ~ 0
TSDZ2_Rx
Text GLabel 7000 3500 0    57   Input ~ 0
TSDZ2_Tx
Text Notes 5300 2650 0    60   ~ 0
Check voltage of DC-DC\nBEFORE WIRING IT UP!!!
Text Label 6550 3000 0    60   ~ 0
5V_Supply
Text GLabel 3200 3100 2    57   Output ~ 0
TSDZ2_GND
Text GLabel 3200 1600 2    57   Output ~ 0
TSDZ2_GND
Text GLabel 4900 3100 0    57   Input ~ 0
TSDZ2_GND
$Comp
L CONN_01X02 P?
U 1 1 5EEB3FFF
P 2300 4500
F 0 "P?" H 2300 4650 50  0000 C CNN
F 1 "Brake_Left" V 2400 4500 50  0000 C CNN
F 2 "" H 2300 4500 50  0000 C CNN
F 3 "" H 2300 4500 50  0000 C CNN
	1    2300 4500
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X02 P?
U 1 1 5EEB409F
P 2300 5000
F 0 "P?" H 2300 5150 50  0000 C CNN
F 1 "Brake_Right" V 2400 5000 50  0000 C CNN
F 2 "" H 2300 5000 50  0000 C CNN
F 3 "" H 2300 5000 50  0000 C CNN
	1    2300 5000
	-1   0    0    -1  
$EndComp
Text GLabel 2900 4450 2    57   Input ~ 0
TSDZ2_GND
Text GLabel 2900 5050 2    57   Output ~ 0
TSDZ2_Brake_Input
Text Notes 5600 1950 0    60   ~ 0
V.Battery MUST!!!!!! be less than 60V otherwise smoke may escape.....
Text Notes 1600 5700 0    60   ~ 0
NOTE - The brake input to the TSDZ2 is pulled up to 5V\nby a resistor inside the motor controller. Pull the input\nto GND to activate. This is normally done with a switch\n(2-Pin Connector). If you have the 8-Way Higo cable\nyou can use a via a powered brake sensor with 3-wires.
$Comp
L CONN_01X03 P?
U 1 1 5EEB45E0
P 2300 6100
F 0 "P?" H 2300 6300 50  0000 C CNN
F 1 "Left_Brake" V 2400 6100 50  0000 C CNN
F 2 "" H 2300 6100 50  0000 C CNN
F 3 "" H 2300 6100 50  0000 C CNN
	1    2300 6100
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X03 P?
U 1 1 5EEB4667
P 2300 6700
F 0 "P?" H 2300 6900 50  0000 C CNN
F 1 "Right_Brake" V 2400 6700 50  0000 C CNN
F 2 "" H 2300 6700 50  0000 C CNN
F 3 "" H 2300 6700 50  0000 C CNN
	1    2300 6700
	-1   0    0    -1  
$EndComp
Text Notes 1450 7050 0    60   ~ 0
NOTE!!!! Pinout will depend on powered brake-sensor model - check first!
Text GLabel 3200 2000 2    57   Output ~ 0
TSDZ2_5V_Output
Text GLabel 3000 6800 2    57   Input ~ 0
TSDZ2_5V_Output
Text GLabel 3000 6000 2    57   Input ~ 0
TSDZ2_GND
Text GLabel 3000 6400 2    57   Output ~ 0
TSDZ2_Brake_Input
Wire Wire Line
	9600 2750 9600 2850
Wire Wire Line
	9600 2850 9200 2850
Wire Wire Line
	9200 2850 9200 2000
Wire Wire Line
	9600 2000 9600 2100
Wire Wire Line
	9500 3150 9500 2750
Wire Wire Line
	9700 2750 9700 2850
Wire Wire Line
	9700 2850 10250 2850
Wire Wire Line
	9500 3550 9500 3650
Wire Wire Line
	5150 2000 9600 2000
Wire Wire Line
	8650 3000 8300 3000
Wire Wire Line
	8300 3100 8650 3100
Wire Wire Line
	8650 3200 8300 3200
Wire Wire Line
	8300 3300 8650 3300
Wire Wire Line
	7200 3100 6300 3100
Wire Wire Line
	6300 2900 6400 2900
Wire Wire Line
	6400 2900 6400 3000
Wire Wire Line
	6400 3000 7200 3000
Wire Wire Line
	2900 3100 3200 3100
Wire Wire Line
	2900 1600 3200 1600
Wire Wire Line
	3200 1700 2900 1700
Wire Wire Line
	3200 1800 2900 1800
Wire Wire Line
	2900 1900 3200 1900
Wire Wire Line
	2900 2100 3200 2100
Wire Wire Line
	2900 2300 3200 2300
Wire Wire Line
	3200 3200 2900 3200
Wire Wire Line
	2900 3300 3200 3300
Wire Wire Line
	3200 3400 2900 3400
Wire Wire Line
	2900 3500 3200 3500
Wire Wire Line
	3200 3600 2900 3600
Wire Wire Line
	6400 3200 6400 3100
Wire Wire Line
	4900 3100 5300 3100
Wire Wire Line
	4900 2900 5300 2900
Wire Wire Line
	5150 2900 5150 2000
Connection ~ 9200 2000
Connection ~ 5150 2900
Wire Wire Line
	8300 3400 9200 3400
Wire Wire Line
	7000 3400 7200 3400
Wire Wire Line
	7200 3500 7000 3500
Connection ~ 6400 3100
Wire Wire Line
	2500 4950 2700 4950
Wire Wire Line
	2700 4950 2700 4450
Wire Wire Line
	2500 4450 2900 4450
Wire Wire Line
	2500 4550 2600 4550
Wire Wire Line
	2600 4550 2600 5050
Wire Wire Line
	2500 5050 2900 5050
Connection ~ 2700 4450
Connection ~ 2600 5050
Wire Wire Line
	3200 2000 2900 2000
Wire Wire Line
	2500 6200 2600 6200
Wire Wire Line
	2600 6200 2600 6800
Wire Wire Line
	2500 6800 3000 6800
Wire Wire Line
	2500 6100 2700 6100
Wire Wire Line
	2700 6100 2700 6700
Wire Wire Line
	2700 6700 2500 6700
Wire Wire Line
	2500 6000 3000 6000
Wire Wire Line
	2800 6000 2800 6600
Wire Wire Line
	2800 6600 2500 6600
Connection ~ 2800 6000
Wire Wire Line
	2700 6400 3000 6400
Connection ~ 2700 6400
Connection ~ 2600 6800
Text Notes 1300 1350 0    60   ~ 0
If you have the TSDZ2 with the throttle option you will\nhave the 8-Way cable. If you don't have a throttle, you\n      are more likely to have the 6-Way cable.
$EndSCHEMATC
