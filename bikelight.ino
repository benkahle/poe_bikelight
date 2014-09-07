// the setup routine runs once when you press reset:
int[] leds = [13, 11, 10, 9, 6];       
unsigned long currentTime;
int counter;
    
void setup() {
  // initialize the digital pin as an output.
  for (int i = 0; i < sizeof(leds)/sizeof(int); i++)
  {
    pinMode(leds[i], OUTPUT);     
  }

  //Set up analog pin for reading
}

void bounce(currentTime) {

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

void flash(currentTime) {

}

// the loop routine runs over and over again forever:
void loop() {
  currentTime = millis(); //get current

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
      flash(currentTime);
      break;
    case 3:
      bounce(currentTime);
      break;
    default:
      break;
  }
}