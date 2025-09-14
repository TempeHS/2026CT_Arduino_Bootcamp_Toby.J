void falldetected() {
  if (digitalRead(button) == HIGH) {
      break;
  } else {

  
    for (int i = 0; i < 5; i++) {
      
        digitalWrite(LED, HIGH);
        delay(100);
        digitalWrite(LED, LOW);

        }
    }
}


void buzzerSound() {
  for (int i = 0; i < 3; i++) {
    for (int freq = 100; freq <= 1000; freq += 10) {
        tone(buzzer, freq);  // Emit a tone
        delay(20);              // Wait before changing the frequency
    }

    // Gradually decrease the pitch
    for (int freq = 1000; freq >= 100; freq -= 10) {
        tone(buzzer, freq);  // Emit a tone
        delay(20); 
                 // Wait before changing the frequency
    }   
  }

}


void buzzerStandby() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= beepInterval) {

    previousMillis = currentMillis;

    tone(buzzer, 1000, beepDuration);

  }
}