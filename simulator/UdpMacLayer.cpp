#include "UdpMacLayer.h"

//TODO: appropriate TCP/IP headers here.


/* 
 * Fake IEEE_802.15.4 MAC Layer
 *
 * 0x00: 0x?? 0x?? Mesh Header Magic Number
 *     : 0x4d 0x63 'M' 'c' - MeshyMcFace Broadcast
 *     : 0xFA 0xCE  .   .  - 16 bit Address
 *     : 0xB0 0xA7  .   .  - 64 bit Address
 *     : 
 * Broadcast.. 
 * 0x02: start of data.
 * Short...... 2 byte addresses
 * 0x02: src address
 * 0x04: dst address
 * 0x06: start of data
 * Long....... 8 bytes addresses
 * 0x02: src address
 * 0x0A: dst address
 * 0x12: start of data
 * 
 */

UdpMacLayer::UdpMacLayer() 
{
}

UdpMacLayer::~UdpMacLayer()
{
}

bool UdpMacLayer::init() 
{
	//TODO: Start listening on bcast socket
}


MACTransmissionStatus UdpMacLayer::send(const IPv6llAddress& lladdr_dest, uint8_t* data, uint16_t length, int &number_transmissions)
{
	//TODO: send packet on broadcast address
} 


bool UdpMacLayer::receive(IPv6llAddress& lladdr_src, IPv6llAddress& lladdr_dest, uint8_t* data, uint16_t& length) 
{
	//Check if packet available, unpack it into appropriate fields
}


const IPv6llAddress& UdpMacLayer::getMacAddress()
{
	return this->my_mac;
}

