#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

const byte pinCE = 9;
const byte pinCSN = 10;
const byte pinPIR = 2;
RF24 radio(pinCE, pinCSN);
char data[16]="Hola mundo" ;

// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup(void)
{
  pinMode(pinPIR, INPUT);
  radio.begin();
  radio.openWritingPipe(pipe);
}
 
void loop(void)
{
  if (digitalRead(pinPIR)) {
    radio.write(data, sizeof data);
  }
  delay(500);
}