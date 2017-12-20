//#include <HardwareSerial.h>
#include "common.h"
#include "uip.h"
#include "arduino_debug.h"

void arduino_debug_init() {
    #if ARDUINO_DEBUG
    //Serial.begin(9600);
    fprintf(stderr, "LOG: %s\n", "INITIALISED");
    #endif
}

void arduino_debug(char* s) {
    #if ARDUINO_DEBUG
    //Serial.println(s);
    fprintf(stderr, "LOG: %s\n", s);
    //delay(20);
    #endif
}

void arduino_debug_hex(int b) {
  #if ARDUINO_DEBUG
    //Serial.println(b, HEX);
    fprintf(stderr, "LOG: %08x\n", b);
    #endif
}

void arduino_debug_dec(long b) {
  #if ARDUINO_DEBUG
    //Serial.println(b, DEC);
    fprintf(stderr, "LOG: %ld\n", b);
    #endif
}
    
void arduino_debug_address(uip_ip6addr_t* address) {
  #if ARDUINO_DEBUG
    fprintf(stderr, "LOG: ");
    int i;
    for (i=0; i<16; i++) {    
      if (address->u8[i]<0xf) 
        //Serial.print("0");   
        fprintf(stderr,"0");   
      //Serial.print(address->u8[i], HEX);
      fprintf(stderr,"%02x",address->u8[i]);
      if (((i%2) == 1) && (i != 15))
        //Serial.print(":");
        fprintf(stderr,":");
    }    
    //Serial.println();  
    fprintf(stderr,"\n");   
    #endif
}

void arduino_debug_lladdr(uip_lladdr_t* address){
  #if ARDUINO_DEBUG
    fprintf(stderr, "LOG: ");
    int i;
    //Serial.print(address->addr[0], HEX);
    fprintf(stderr,"%02x", address->addr[0]);
    for (i=1; i< UIP_LLADDR_LEN; i++) {  
      fprintf(stderr,":%02x", address->addr[i]);
      //Serial.print(":");
      //Serial.print(address->addr[i], HEX);
    }
    //Serial.println();  
    fprintf(stderr,"\n");   
    #endif
}

    
    
