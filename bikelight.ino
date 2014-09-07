// the setup routine runs once when you press reset:
void setup() {
  int[] leds = [13, 11, 10, 9, 6];           
  // initialize the digital pin as an output.
  for (int i = 0; i < sizeof(leds)/sizeof(int); i++)
  {
    pinMode(leds[i], OUTPUT);     
  }
}

// the loop routine runs over and over again forever:
void loop() {
  unsigned long time;
  time = millis(); //get current
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}