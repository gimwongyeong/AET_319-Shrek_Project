#include <Servo.h>

//Create servo variables
Servo potionServo;
Servo fixtureServo;
Servo bucketServo;

//Create servo sensor variables
const int potionServoSensor = 2;
const int fixtureServoSensor = 4;
const int bucketServoSensor = 6;

//Create LED & piezo pin variables
const int potionSensor = 8;
const int potionLED = 9;
const int alarmSensor = 10;
const int alarmLED = 11;
const int alarmPiezo = 12;

void setup() {
  //Attach servos to pins
  potionServo.attach(3);
  fixtureServo.attach(5);
  bucketServo.attach(7);

  //Set pin modes
  pinMode(potionServoSensor, INPUT);
  pinMode(fixtureServoSensor, INPUT);
  pinMode(bucketServoSensor, INPUT);
  
  pinMode(potionSensor, INPUT);
  pinMode(potionLED, OUTPUT);
  pinMode(alarmSensor, INPUT);
  pinMode(alarmPiezo, OUTPUT);
  pinMode(alarmLED, OUTPUT);
}

void loop() {
  //Interaction 1: Potion LED
  if (digitalRead(potionSensor) == HIGH) {
    digitalWrite(potionLED, HIGH);
  } else {
    digitalWrite(potionLED, LOW);
  }
  
  //Interaction 2: Potion servo
  if (digitalRead(potionServoSensor) == HIGH) {
    potionServo.write(125);
  } else {
    potionServo.write(35);
  }
  
  //Interaction 3: Alarm LED & piezo
  if (digitalRead(alarmSensor) == HIGH) {
    digitalWrite(alarmPiezo, HIGH);
    digitalWrite(alarmLED, HIGH);
  } else {
    digitalWrite(alarmPiezo, LOW);
    digitalWrite(alarmLED, LOW);
  }

  //Interaction 4: Fixture servo
  if (digitalRead(fixtureServoSensor) == HIGH) {
    fixtureServo.write(180);
  } else {
    fixtureServo.write(0);
  }

  //Interaction 5: Bucket servo
  if (digitalRead(bucketServoSensor) == HIGH) {
    bucketServo.write(0);
  } else {
    bucketServo.write(90);
  }
}
