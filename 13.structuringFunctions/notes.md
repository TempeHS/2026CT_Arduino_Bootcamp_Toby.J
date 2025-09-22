# Fall Detection System

This system is able to detect if a user falls over  or is harmed in any way. 
It uses accelerometers and sound detectors to detect if a user has fallen or slipped, and can detect if screaming or shouting from pain is heard. 
If a fall is detected, the screen will print that the user has fallen, play a beeping noise and flash an LED. This great for peopel prone to falling, and is a great way to announce a fall if the person is unresponsive.

| Sensor | Use | Pin |
| ------ | --- | --- |
| Accelerometer | Senses movement | I2C |
| Sound detector | Sense loud noises | 5 |
| Buzzer | Auditory Alert | 4 |
| LED | Visual Alert | 6 |
| OLED Screen | Visual message | I2C |



'''FALL DETECTOR
BEGIN

  SETUP Accelerometer
  SETUP LED
  SETUP Buzzer
  SETUP button

  WHILE power == on
    READ Accelerometer X,Y,Z
    
    IF Accelerometer Z > 3.5 THEN
      fallen = true


    IF fallen == TRUE THEN
      Flash LED
      Sound Buzzer

    IF button == PRESSED THEN
      STOP Flashing LED
      STOP Sounding buzzer
      fallen = FALSE 
    DELAY(1000)


'''END


----------------------------------------------------------------------------------------------------------





# VIVIAN Exertion detector

I have also chosen to create a device for Vivian, which will monitor her vitals.


| Sensor | Use | Pin |
| ------ | --- | --- |
| Temperature | Senses temperature | I2C |
| Heart Rate | Sense heart rate | 5 |
| Buzzer | Auditory Alert | 4 |
| OLED Screen | Visual message | I2C |


'''EXERTION DETECTOR
BEGIN
  SETUP Temperature sensor
  SETUP Heart rate sensor
  SETUP Buzzer
  SETUP Button
  SETUP OLED Screen

  WHILE power == on {
    READ Temperature sensor
    READ Heart rate sensor

    IF temp >= 25 || HR >= 90 {
      WARNING = true
    } 

    while WARNING {
      SOUND Buzzer
      PRINT Oled Screen warning

      if button {
        WARNING = false
      }
    }
  }
    
'''END

----------------------------------------------------------------------------------------------------------


I have chosen to create a biomedical device for Faia, which will help her navigate her school.

| Sensor | Use | Pin |
| ------ | --- | --- |
| Gesture | Senses gestures | I2C |
| Motion sensor | Sense motion | 5 |
| Buzzer | Auditory Alert | 4 |
| Vibration motor | Haptic feedback | I2C |


'''BLIND ASSISTANCE
BEGIN
  SETUP Gesture sensor
  SETUP Motion sensor
  SETUP Buzzer
  SETUP Vibration motor

  WHILE power == on
    READ Gesture sensor
    IF gesture == OK {
      operating = true
    } 
    IF Gesture == PALM {
      operating = false }

    while operating {
      IF motion < 2 meters {
        SOUND Buzzer
        SPIN Vibration motor
        delay(1000)
      }
    }
    
'''END


 