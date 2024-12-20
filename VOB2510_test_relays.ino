#include <Wire.h>

#define cbi(sfr, bit)             (_SFR_BYTE(sfr) &= ~_BV(bit)) // Utilizado para poner a 0 el bit indicado por bit del registro indicado sfr
#define sbi(sfr, bit)             (_SFR_BYTE(sfr) |= _BV(bit))  // Utilizado para poner a 1 el bit indicado por bit del registro indicado sfr
#define relayNumToDigitalPin(P)   ( pgm_read_byte( relay_num_to_digital_pin + (P-1) ) ) // Macro que devuelve el pin correspondiente a un rele



void setup() {
  for (int i = 1; i <= 21; i++){
    uint8_t num_pin = relayNumToDigitalPin(i);
    digitalWrite(num_pin, LOW);
  }
}

                        

void loop() {
  for (int i = 1; i <= 21; i++){
    uint8_t num_pin = relayNumToDigitalPin(i); // Obtenemos el numero de pin correspondiente al rele
    digitalWrite(num_pin, HIGH);
    if (i>1){
      uint8_t num_pin = relayNumToDigitalPin(i-1); // Obtenemos el numero de pin correspondiente al rele
      digitalWrite(num_pin, LOW);
    }
    else{
      uint8_t num_pin = relayNumToDigitalPin(21); // Obtenemos el numero de pin correspondiente al rele
      digitalWrite(num_pin, LOW);
    }
    delay(1000);
  } 
}
