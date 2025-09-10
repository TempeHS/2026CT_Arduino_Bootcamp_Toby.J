#include <LIS3DHTR.h>
#include <Wire.h>
LIS3DHTR<TwoWire> LIS; //IIC
#define WIRE Wire
 int LED = 6;
 int buzzer = 7;
 bool fallen = false;



void setup() {
  Serial.begin(9600);
  LIS.begin(WIRE, LIS3DHTR_ADDRESS_UPDATED); //IIC init
  delay(100);
  LIS.setOutputDataRate(LIS3DHTR_DATARATE_50HZ);
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(LED, LOW);

}

void loop() {

   Serial.print("x:"); Serial.print(LIS.getAccelerationX()); Serial.print("  ");
   Serial.print("y:"); Serial.print(LIS.getAccelerationY()); Serial.print("  ");
   Serial.print("z:"); Serial.println(LIS.getAccelerationZ());

   if (LIS.getAccelerationZ() > 1.5) {
    for ( int i = 0; i < 5; i++) {
      digitalWrite(LED, HIGH);
      delay(100);
      digitalWrite(LED, LOW);
      tone(buzzer, 500, 500);
      

    }
    
   } else {
    digitalWrite(LED, LOW);
   }
}

