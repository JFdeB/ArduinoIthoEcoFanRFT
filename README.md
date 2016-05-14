# ArduinoIthoEcoFanRFT
Program to controll an Itho Fan by Arduino and CC1101 868 MHz
The program controlls an IthoEcoFanRFT. The program runs on an Arduino (tested on MiniPro 3.3V 8 MHz)
The program is based on the extensive work of Rogier Reedijk, Jimmy and Klusjesman for decoding the messages that need to be send to the IthoEcoFan (http://www.progz.nl/blog/index.php/2015/05/reverse-engineering-remote-itho-cve-eco-rft-part-6/), and on the software written by Klusjesman with significant contributions from Rogier Reedijk and Jimmy for ATMega328P (https://github.com/Klusjesman/IthoEcoFanRFT). The software was slightly modified to run on Arduino. The project was compiled and tested with Arduino 1.6.9 on Mac.
The hardware used for this project was: Arduino Pro Mini 3.3V/8MHZ and a CC1101 module 868 MHz. The following lines were connected betweenPro Mini and CC1101: 3.3V, Ground, (MO)SI, SCLK, (MI)SO, and CSN (Chip Select). See the file Circuit Mini Pro and CC1101 module Pin connections.pdf for a picture and color coded connections.

To compile and load the program using arduino IDE,  place the BBuart.S and the BBuart.h file in a directory named BBuart in the libraries directory of your Arduino folder.
Place all other files in a program directory named ArduinoIthoEcoFan.
In the BBuart.S file the port is set to PortD (serial port on the Pro Mini is on portD)
The UART_TX is set to 1 (PD1)
The UART_RX is set to 0 (PD0)

Happy experimenting!
