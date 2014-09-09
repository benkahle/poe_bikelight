// the setup routine runs once when you press reset:
int[] leds = [13, 11, 10, 9, 6];       
unsigned long currentTime;
unsigned long sampleTime;
unsigned long lastButtonTime;
int counter;
int mode;

void setup() {
  // initialize the digital pin as an output.
  for (int i = 0; i < sizeof(leds)/sizeof(int); i++)
  {
    pinMode(leds[i], OUTPUT);     
  }
  pinMode(SET_THIS_VALUE_RY, INPUT);
  sampleTime = millis() + 100;
  //Set up analog pin for reading
}

void bounce(currentTime,lastButtonTime) {
  timeDiff = (currentTime - lastButtonTime) / 100;
  positionOn = floor(timeDiff) % 8;
  if (positionOn == 0) {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], LOW);
  } else if (positionOn == 1) {
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[0], LOW);
    digitalWrite(leds[2], LOW);
  } else if (positionOn == 2) {
    digitalWrite(leds[2], HIGH);
    digitalWrite(leds[1], LOW);
    digitalWrite(leds[3], LOW);
  } else if (positionOn == 3) {
    digitalWrite(leds[3], HIGH);
    digitalWrite(leds[2], LOW);
    digitalWrite(leds[4], LOW);
  } else if (positionOn == 4) {
    digitalWrite(leds[4], HIGH);
    digitalWrite(leds[3], LOW);
  }
}

void setAllLeds(setPoint) {
  for (int i = 0; i < sizeof(leds)/sizeof(int); i++)
  {
    digitalWrite(leds[i], setPoint);     
  }
}

void allOn() {
  setAllLeds(HIGH);
}

void off() {
  setAllLeds(LOW);
}

void flash(currentTime, lastButtonTime) {
  timeDiff = (currentTime - lastButtonTime) / 100;
  ledState = floor(timeDiff) % 2;
  if (ledState == 0) {
    setAllLeds(HIGH);
  } else {
    setAllLeds(LOW)
  }
}

// the loop routine runs over and over again forever:
void loop() {
  currentTime = millis(); //get current

  if (mode == NULL)
  {
    mode = 0;
    lastButtonTime = currentTime
  }

  if (currentTime == sampleTime) {
    //Read digital in
    buttonPress = digitalRead(SET_THIS_VALUE_RY);
    if (buttonPress == HIGH) {
      counter = counter + 1;
      lastButtonTime = currentTime
    }
    sampleTime = currentTime + 100;
  }

setPoint
  //EXAMPLE
  int pinNumber = 13;
  digitalWrite(pinNumber, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
  //END EXAMPLE

  //Read analog in, change counter as needed, choose which function to call
  //if Ain high, increment counter, dont read button again for ~100ms

  int mode = counter % 4;
  switch(mode) {
    case 0:
      allOff();
      break;
    case 1;
      allOn();
      break;
    case 2:
      flash(currentTime,lastButtonTime);
      break;
    case 3:
      bounce(currentTime,lastButtonTime);
      break;
    default:
      break;
  }
}