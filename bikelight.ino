int leds[] = {13, 11, 10, 9, 6};
int buttonPin = 4;
int analogPin = 0;
int speed = 250;
unsigned long currentTime = 0;
unsigned long sampleTime;
unsigned long lastButtonTime;
int counter = 0;
int mode = 0;
int sampleDelay = 50;

void setup() {
  Serial.begin(9600);
  // initialize the digital pin as an output.
  for (int i = 0; i < sizeof(leds)/sizeof(int); i++)
  {
    pinMode(leds[i], OUTPUT);     
  }
  pinMode(buttonPin, INPUT);
  sampleTime = millis() + sampleDelay;
  //Set up analog pin for reading
}

void oneOn(int ledIndex) {
  for (int i=0; i < sizeof(leds)/sizeof(int); i++) {
    if (i == ledIndex) {
      digitalWrite(leds[i], HIGH);
    } else {
      digitalWrite(leds[i], LOW);
    }
  }
}

void bounce(unsigned long currentTime, unsigned long lastButtonTime) {
  unsigned long timeDiff = (currentTime - lastButtonTime) / speed;
  int positionOn = (int)floor(timeDiff) % 8;
  if (positionOn > 4) {
    positionOn = 8 - positionOn;
  }
  oneOn(positionOn);
}

void setAllLeds(int setPoint) {
  for (int i = 0; i < sizeof(leds)/sizeof(int); i++)
  {
    digitalWrite(leds[i], setPoint);     
  }
}

void allOn() {
  setAllLeds(HIGH);
}

void allOff() {
  setAllLeds(LOW);
}

void flash(unsigned long currentTime, unsigned long lastButtonTime) {
  unsigned long timeDiff = (currentTime - lastButtonTime) / speed;
  int ledState = (int)floor(timeDiff) % 2;
  if (ledState == 0) {
    setAllLeds(HIGH);
  } else {
    setAllLeds(LOW);
  }
}

void loop() {
  currentTime = millis(); //get current

  speed = analogRead(analogPin); // 0-1023
  if (speed < 25) {
    speed = 25;
  }


  int buttonPress;

  if (currentTime >= sampleTime) {
    //Read digital in
    buttonPress = digitalRead(buttonPin);
    if (buttonPress == HIGH) {
      counter++;
      lastButtonTime = currentTime;
    }
    sampleTime = currentTime + sampleDelay;
  }

  int mode = counter % 4;
  switch(mode) {
    case 0:
      allOff();
      break;
    case 1:
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