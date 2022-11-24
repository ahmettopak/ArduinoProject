//Ahmet TOPAK 2022. 


#include <IRremote.h>

const int RECV_PIN = 4;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define forward 0xFF18E7
#define back 0xFF4AB5
#define stop 0xFF38C7
#define left 0xFF20C7
#define right 0xFF25C7

const int inputA1 = 8;
const int inputA2 = 9;
const int inputB1 = 10;
const int inputB2 = 11;
const int inputB2 = 12;
const int inputB2 = 13;


void setup()
{

  pinMode(inputA1, OUTPUT);
  pinMode(inputA2, OUTPUT);
  pinMode(inputB1, OUTPUT);
  pinMode(inputB2, OUTPUT);
  pinMode(speedleft, OUTPUT);
  pinMode(speedright, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();


}


void loop() {
 if (irrecv.decode(&results)){

    if (results.value == forward){
      digitalWrite(inputA1, HIGH);
      digitalWrite(inputA2, LOW);
      digitalWrite(inputB1 , HIGH);
      digitalWrite(inputB2, LOW);
    }

    if (results.value == back){
      digitalWrite(inputA1, LOW);
      digitalWrite(inputA2, HIGH);
      digitalWrite(inputB1 , LOW);
      digitalWrite(inputB2, HIGH);
    }

    if (results.value == stop){
      digitalWrite(inputA1, LOW);
      digitalWrite(inputA2, LOW);
      digitalWrite(inputB1 , LOW);
      digitalWrite(inputB2, LOW);
    }
    if (results.value == left){
      digitalWrite(inputA1, LOW);
      digitalWrite(inputA2, HIGH);
      digitalWrite(inputB1 , HIGH);
      digitalWrite(inputB2, LOW);
    }

    if (results.value == ok){
      digitalWrite(inputA1, HIGH);
      digitalWrite(inputA2, LOW);
      digitalWrite(inputB1 , LOW);
      digitalWrite(inputB2, HIGH);
    }
    
    irrecv.resume();
  }

}
