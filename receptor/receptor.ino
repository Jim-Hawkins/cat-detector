#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

const byte pinCE = 9;
const byte pinCSN = 10;
const byte pinLED = 2;
const byte pinBuzzer = 3;
char data[16];

// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;

RF24 radio(pinCE, pinCSN);

void setup(void)
{
  pinMode(pinLED, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  digitalWrite(pinLED, LOW);
  noTone(pinBuzzer);
  
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
}
 
void loop(void)
{
  if (radio.available()) {
    //radio.read(data, sizeof data);
    digitalWrite(pinLED, HIGH);    // LED on
    tone(pinBuzzer, 800);          // buzzer on
  }
  // each 500 ms
  delay(500);
  digitalWrite(pinLED, LOW);       // LED off
  noTone(pinBuzzer);               // buzzer off
}