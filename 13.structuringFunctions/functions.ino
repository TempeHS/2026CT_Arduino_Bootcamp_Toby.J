void buzzerStandby() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= beepInterval) {

    previousMillis = currentMillis;

    tone(buzzer, 1000, beepDuration);

  }
}


9
void buzzerSound() {
  for (int i = 0; i < 3; i++) {
    for (int freq = 100; freq <= 1000; freq += 10) {
        tone(buzzer, freq);
        delay(20);          
    }


    for (int freq = 1000; freq >= 100; freq -= 10) {
        tone(buzzer, freq);
        delay(20); 

    }   
  }

}

void falldetected() {

  for (int i = 0; i < 5; i++) {
      if (digitalRead(button) == LOW) {
          return;
      }

      digitalWrite(LED, HIGH);
      delay(100);
      digitalWrite(LED, LOW);
  }
  }
