#include <LIS3DHTR.h>
#include <Wire.h>
LIS3DHTR<TwoWire> LIS; //IIC
#define WIRE Wire
int LED = 6;
int buzzer = 7;
int button = 5;
bool fallen = false;
const int beepDuration = 150;
const int beepInterval = 2000;
unsigned long previousMillis = 0;


void setup() {
  Serial.begin(9600);
  LIS.begin(WIRE, LIS3DHTR_ADDRESS_UPDATED); //IIC init
  delay(100);
  LIS.setOutputDataRate(LIS3DHTR_DATARATE_50HZ);
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(LED, LOW);
  pinMode(button, INPUT);

}

void loop() {
  buzzerStandby();

   Serial.print("x:"); Serial.print(LIS.getAccelerationX()); Serial.print("  ");
   Serial.print("y:"); Serial.print(LIS.getAccelerationY()); Serial.print("  ");
   Serial.print("z:"); Serial.println(LIS.getAccelerationZ());

   if (LIS.getAccelerationZ() > 3.5) {
    falldetected();
    buzzerSound();
   }
}




