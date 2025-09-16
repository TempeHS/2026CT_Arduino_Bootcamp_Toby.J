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
 