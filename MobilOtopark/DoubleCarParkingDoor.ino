#include <Servo.h>
Servo ServoGiris;
Servo ServoCikis;
int KapiAcik = 100;
int KapiKapali = 0;


#define trigPin1 3
#define echoPin1 2
#define trigPin2 4
#define echoPin2 5
#define trigPin3 7
#define echoPin3 13

long duration, distance, SensorGiris, BackSensor, FrontSensor, SensorCikis;

void setup()
{
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  ServoGiris.attach(8);
  ServoCikis.attach(9);
   
}

void loop() {
  SonarSensor(trigPin1, echoPin1);
  SensorGiris = distance;
  SonarSensor(trigPin2, echoPin2);
  SensorCikis = distance;
  SonarSensor(trigPin3, echoPin3);
  FrontSensor = distance;

  if (SensorGiris <= 5) {

    Serial.println("Giris Acik");
    ServoGiris.write(KapiAcik);
  }
  else{
    ServoGiris.write(KapiKapali);
    
    }

  if (SensorCikis  <= 5) {

    Serial.println("Cikis Acik");
    ServoCikis.write(KapiAcik);
  }
  else{
    ServoCikis.write(KapiKapali);
    }

  Serial.print(SensorGiris);
  Serial.print(" - ");
  Serial.print(FrontSensor);
  Serial.print(" - ");
  Serial.println(SensorCikis);
}

void SonarSensor(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

}
