/*
  Author: 

  Learning Intention:
  The students will learn how to wire a variable resistor as a pseudo sensor and read analogue
  data from that PIN.
  
  Success Criteria:
    1.  I can wire a variable resistor in TINKERCAD
    2.  I know how to read analogue data from a specific PIN
    3.  I know the range of analogue data
    4.  I can organise output data so it correctly plots on the serial monitor
    5.  I can apply this knowledge to the Light, Sound and Rotary Potentiometer in the sensor kit

  Student Notes: 

  Documentation: 
    https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/
  Schematic:
    https://www.tinkercad.com/things/97wMDip2Ata-bootcamp-analogueread/editel
    https://github.com/TempeHS/TempeHS_Ardunio_Bootcamp/blob/main/05.analogueRead/Bootcamp-analogueRead.png
*/
static unsigned int myVariableResistor = A0;
unsigned int resistorValue;
static unsigned int LED1 = 8;
static unsigned int LED2 = 13;



void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  // analog pins do not need to be configured unless ou want to use one as a digital I/O
}

void loop() {
  Serial.print("myVariableResistor:");
  resistorValue = analogRead(myVariableResistor);
  Serial.println(resistorValue);

  if (resistorValue >= 50) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
   } else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
  }
}

