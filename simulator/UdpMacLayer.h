

#ifndef UDPMACLAYER_H
#define UDPMACLAYER_H

#include "MACLayer.h"
#include "arduino.h"


class  UdpMacLayer : public MACLayer {

  public:
	  UdpMacLayer();
	  ~UdpMacLayer();
	  bool init(); 
	  MACTransmissionStatus send(const IPv6llAddress& lladdr_dest, uint8_t* data, uint16_t length, int &number_transmissions); 
	  bool receive(IPv6llAddress& lladdr_src, IPv6llAddress& lladdr_dest, uint8_t* data, uint16_t& length); 
	  const IPv6llAddress& getMacAddress();
  private: 
	  IPv6llAddress my_mac; 

};

#endif
