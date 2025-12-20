const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;
const int buttonPin = 2;

int mode = 1;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading == HIGH && lastButtonState == LOW) {
    if (millis() - lastDebounceTime > debounceDelay) {
      mode++;
      if (mode > 3) mode = 1;  // 三模式循環
      lastDebounceTime = millis();
    }
  }
  lastButtonState = reading;

  switch (mode) {
    case 1: // Red ON
      setColor(255, 0, 0);
      break;

    case 2: // Blue slow blink
      blinkColor(0, 0, 255, 800);
      break;

    case 3: // RGB cycle
      rainbowBlink();
      break;
  }
}

void setColor(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

void blinkColor(int r, int g, int b, int interval) {
  setColor(r, g, b);
  delay(interval);
  setColor(0, 0, 0);
  delay(interval);
}

void rainbowBlink() {
  setColor(255, 0, 0);
  delay(300);
  setColor(0, 255, 0);
  delay(300);
  setColor(0, 0, 255);
  delay(300);
}
