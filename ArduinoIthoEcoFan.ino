/*
 * Author: Klusjesman
 * Modified for Arduino by JFdB
 * Tested with Ardiuno Pro Mini 3.3V 8 MHz, Arduino compiler 1.6.9 on Mac
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include "millis.h"
#include "delay.h"
#include "SerialDebug.h"
#include "IthoCC1101.h"
#include "IthoPacket.h"

millis_t last;
IthoPacket packet;
//slave select CC1101
DigitalPin ss(&PORTB,2);
//init SPI
SPI spi(&ss);
//init CC1101
IthoCC1101 rf(&spi);


void setup(){

  millis_init();
  delay_ms(500);
  
  //set up SPI
  spi.init();
  
  //init CC1101
  rf.init();
  
  //set CC1101 registers
  rf.initReceive();
      
  debug.serOut("start\n");
  last = millis();
  sei();
}

void loop()
{

		if (rf.checkForNewPacket())
		{
			packet = rf.getLastPacket();
			
			//show counter
			debug.serOut("counter=");
			debug.serOutInt(packet.counter);
			debug.serOut(", ");
			
			//show command
			switch (packet.command)
			{
				case unknown:
					debug.serOut("unknown\n");
					break;
				case low:
					debug.serOut("low\n");
					break;
				case medium:
					debug.serOut("medium\n");
          //Serial.print("medium\n");
					break;
				case full:
					debug.serOut("full\n");
          //Serial.print("full\n");
					break;
				case timer1:
					debug.serOut("timer1\n");
					break;
				case timer2:
					debug.serOut("timer2\n");
					break;
				case timer3:
					debug.serOut("timer3\n");
					break;
				case join:
					debug.serOut("join\n");
					break;
				case leave:
					debug.serOut("leave\n");
					break;
			}
				
		}
		
		if (millis() - last > 5000)
		{
			last = millis();
      rf.sendCommand(low); // or low, medium, full, timer1, timer2, timer3, join, leave
      rf.initReceive();
		}
}


