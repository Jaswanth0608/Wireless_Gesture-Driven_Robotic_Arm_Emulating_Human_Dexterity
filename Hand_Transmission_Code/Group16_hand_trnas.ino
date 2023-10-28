#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

RF24 radio(9,10);   // declaring CE and CSN pins
const byte address[]="16523";

bool buttonCheck1=0;
bool buttonCheck2=0;
bool buttonCheck3=0;
bool buttonCheck4=0;
bool buttonCheck5=0;
void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();    
 
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  
}
                                                                          
void loop() {
  buttonCheck1=analogRead(A1);
  buttonCheck2=analogRead(A2);
  buttonCheck3=analogRead(A3);
  buttonCheck4=analogRead(A4);
  buttonCheck5=analogRead(A5);
  radio.write(&buttonCheck1, sizeof(buttonCheck1));
  radio.write(&buttonCheck2, sizeof(buttonCheck2));
  radio.write(&buttonCheck3, sizeof(buttonCheck3));
  radio.write(&buttonCheck4, sizeof(buttonCheck4));
  radio.write(&buttonCheck4, sizeof(buttonCheck5));
  
}
