/*
 * Author: Klusjesman
 */

#ifndef CC1101PACKET_H_
#define CC1101PACKET_H_

#include <stdio.h>

#define CC1101_BUFFER_LEN        64
#define CC1101_DATA_LEN          CC1101_BUFFER_LEN - 3


class CC1101Packet
{
	public:
		uint8_t length;
		uint8_t data[72];
};


#endif /* CC1101PACKET_H_ */
