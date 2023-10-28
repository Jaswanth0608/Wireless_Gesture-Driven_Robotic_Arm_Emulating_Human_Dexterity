#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
#include <Servo.h>

int pos = 0;

Servo servo_1;
Servo servo_2;
Servo servo_3;
Servo servo_4;
Servo servo_5;

int j_1,j_2,j_3,j_4,j_5;

RF24 radio(9,10); // declaring CE and CSN pins
const byte address[]="16523";

bool buttonState1=0;
bool buttonState2=0;
bool buttonState3=0;
bool buttonState4=0;
bool buttonState5=0;

void setup(){
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  
  servo_1.attach(A1);
  servo_2.attach(A2);
  servo_3.attach(A3);
  servo_4.attach(A4);
  servo_5.attach(A5);
}


void loop() {
  while(radio.available()){
    radio.read(&buttonState1, sizeof(buttonState1));
    if(buttonState1){
      for (pos = 0; pos <= 180; pos += 45){
      servo_1.write(pos);
      j_1=pos;
      delay(10);
      }
    }
    else if(buttonState1==0 && j_1>0){
      servo_1.write(0);
    }
    radio.read(&buttonState2, sizeof(buttonState2));
    if(buttonState2){
      for (pos = 0; pos <= 180; pos += 45){
      servo_2.write(pos);
      j_2=pos;
      delay(10);
      }
    }
    else if(buttonState2==0 && j_2>0){
      servo_2.write(0);
    }
    
    radio.read(&buttonState3, sizeof(buttonState3));
    if(buttonState3){
      for (pos = 0; pos <= 180; pos += 45){
      servo_3.write(pos);
      j_3=pos;
      delay(10);
      }
    }
    else if(buttonState3==0 && j_3>0){
      servo_3.write(0);
    }
    
    radio.read(&buttonState4,sizeof(buttonState4));
    if(buttonState4){
      for (pos = 0; pos <= 180; pos += 45){
      servo_4.write(pos);
      j_4=pos;
      delay(10);
      }
    }
    else if(buttonState4==0 && j_4>0){
      servo_4.write(0);
    }
    
    radio.read(&buttonState5,sizeof(buttonState5));
    if(buttonState5){
      for (pos = 0; pos <= 180; pos += 45){
      servo_5.write(pos);
      j_5=pos;
      delay(10);
      }
    }
    else if(buttonState5==0 && j_5>0){
      servo_5.write(0);
    }
  }
}
