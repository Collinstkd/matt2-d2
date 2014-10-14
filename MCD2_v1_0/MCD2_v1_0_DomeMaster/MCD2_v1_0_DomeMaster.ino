#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#include <Servos.h>

Servos DomeServoBoard(0x40);

#define LED_PIN 13

const int SERVO_0 = 0;

int x;

void setup() {
  Wire.begin(9);                // Start I2C Bus as a Slave (Device Number 9)
  Wire.onReceive(receiveEvent); // register event
  
  pinMode(LED_PIN, OUTPUT);
 
  digitalWrite(LED_PIN, LOW);
    
  x = 0;
}

void loop() {
  Servos::move(millis());  // this performs the actual moves
  //If value received is 0 blink LED 1
  if (x == 3) {
    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    
   //DomeServoBoard.moveTo(1, 0 ,300, 200);
   
  
   DomeServoBoard.moveTo(1, 1000 ,200,600);
   DomeServoBoard.moveTo(0, 2000 ,200,500);
    x=0;
  }
 
}

void receiveEvent(int howMany) {
  x = Wire.read();    // receive byte as an integer
}


