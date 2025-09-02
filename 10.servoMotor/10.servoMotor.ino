/*
  Author:

  Learning Intention:
  The students will learn how to connect and control a servo motor.

  Success Criteria:
    1.  I understand how to connect the servo motor
    2.  I can manually write different degrees of movement to the servo
    3.  I can map a potentiometer to a servo and control its movement
    4.  I understand that a 180deg servo angle of movement is set by a
        frequency signal sent from the microcontroller

  Student Notes: 

  Documentation:
    https://www.sparkfun.com/servos
    https://github.com/arduino-libraries/Servo <-- We are still using this library

  Schematic:
    https://www.tinkercad.com/things/lQ9RyYJRoLn?sharecode=MKlN0A7R0WGodkdTRKkPJO7I8PeI5L_GCR7pCclQ0qM
    https://github.com/TempeHS/TempeHS_Ardunio_Bootcamp/blob/main/10.servoMotor/Bootcamp-servoMotor.png
*/
//Includes or OLED screen
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

#include <Servo.h>

#include "Ultrasonic.h"
Ultrasonic myUltraSonicSensor(5);

unsigned static int servoPin = 6;
unsigned static int usPin = 5;
Servo myservo;

int val;
int potpin = A1;

U8G2_SSD1306_128X64_NONAME_F_HW_I2C OLED(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);

void setup() {
  myservo.attach(servoPin);
  Serial.begin(9600);

  OLED.begin();
  OLED.setFont(u8g2_font_6x12_tf);
  OLED.drawStr(0,10,"Ultrasonic Sensor");
  OLED.drawStr(0,20,"---------------------");
  OLED.nextPage();
  delay(3000);
}

void loop(){
  

  String inputString = "10cm";
  String cleanString = "";

  for (unsigned int i = 0; i < inputString.length(); i++) {
    char inChar = inputString[i];
    if (inChar != '\n' && inChar != '\r') {
      cleanString += inChar;
    }
    if(inChar == '\n'){
      cleanString += '_';
    }
  }
  OLED.clearBuffer();
  OLED.print(cleanString);
  delay(1000);
  
}