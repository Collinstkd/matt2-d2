#include <Wire.h>
#include <PS3BT.h>
#include <usbhub.h>

// Satisfy IDE, which only needs to see the include statment in the ino.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif


USB Usb;


BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so

PS3BT PS3(&Btd, 0x00, 0x15, 0x83, 0x0C, 0xBF, 0xEB); // This will also store the bluetooth address - this can be obtained from the dongle when running the sketch

String inString = "";

void setup() {
  Wire.begin(); // Start I2C Bus as Master

  Serial.begin(19200);

  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));
}
void loop() {
 

  
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char 
      // and add it to the string:
      inString += (char)inChar; 
    }
    // if you get a newline, print the string,
    // then the string's value:
    if (inChar == '\n') {
      Serial.print("Value:");
      Serial.println(inString.toInt());
      
      Serial.print("String: ");
      Serial.println(inString);
      // clear the string for new input:
      inString = ""; 
    }
  }
  
  

  
  Usb.Task();

  if (PS3.PS3NavigationConnected) {
    if (PS3.getAnalogHat(LeftHatX) > 137 || PS3.getAnalogHat(LeftHatX) < 117 || PS3.getAnalogHat(LeftHatY) > 137 || PS3.getAnalogHat(LeftHatY) < 117 || PS3.getAnalogHat(RightHatX) > 137 || PS3.getAnalogHat(RightHatX) < 117 || PS3.getAnalogHat(RightHatY) > 137 || PS3.getAnalogHat(RightHatY) < 117) {
      
       
    }

    // Analog button values can be read from almost all buttons
    if (PS3.getAnalogButton(L2) ) {
   
    }
    
    if (PS3.getButtonClick(L2) ) {
     
    }
    
    if (PS3.getButtonClick(PS)) {
      
      PS3.disconnect();
    }
    else {
      
      if (PS3.getButtonClick(CIRCLE))
      {
        
         Wire.beginTransmission(9); // transmit to device #9
  Wire.write(3);              // sends x 
  Wire.endTransmission();    // stop transmitting

      }
      if (PS3.getButtonClick(CROSS))
      {
      }
      if (PS3.getButtonClick(UP)) {
       
       
      }
      if (PS3.getButtonClick(RIGHT)) {
        
      }
      if (PS3.getButtonClick(DOWN)) {
       
      }
      if (PS3.getButtonClick(LEFT)) {
       
      }

      if (PS3.getButtonClick(L1))
        Serial.print(F("\r\nL1"));
      if (PS3.getButtonClick(L3))
        Serial.print(F("\r\nL3"));
    
     
    }
    
  }
  
}
