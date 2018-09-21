#include <IRremote.h>

const int RECV_PIN = 0;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int forPin = 13;
const int backPin = 12;


void setup(){
  irrecv.enableIRIn();
  pinMode(forPin, OUTPUT);
  pinMode(backPin, OUTPUT);
}

void loop(){
    if (irrecv.decode(&results)){

        switch(results.value){
          case 0x1FE50AF: //Keypad button "1"
           delay(50);
          digitalWrite(backPin, LOW);
          digitalWrite(forPin, LOW);
          delay(2000);
          digitalWrite(forPin, HIGH);
          digitalWrite(backPin, LOW);
          }

        switch(results.value){
          case 0x1FED827: //Keypad button "2"
          delay(50);
          digitalWrite(backPin, LOW);
          digitalWrite(forPin, LOW);
          delay(2000);
          digitalWrite(backPin, HIGH);
          digitalWrite(forPin, LOW);
          }
          
        switch(results.value){
          case 0x1FE48B7: //Keypad button "POWER"
          delay(50);
          digitalWrite(backPin, LOW);
          digitalWrite(forPin, LOW);
          }

        irrecv.resume(); 
    }
}

