const int RledPin = 9;
const int GledPin = 10;
const int BledPin = 11;
const int buttonPin = 2;

bool buttonPressed = false;
int brightness = 30; // 初始微亮黃光
int fadeAmount = 5;
unsigned long lastPress = 0;

void setup() {
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  showYellow(brightness);
}

void loop() {
  if (digitalRead(buttonPin) == LOW && millis() - lastPress > 300) {
    lastPress = millis();
    buttonPressed = true;
  }

  if (buttonPressed) {
    for (int b = brightness; b <= 255; b += fadeAmount) {
      showYellow(b);
      delay(30);
    }

    showRed(255);
    delay(3000);

    for (int i = 0; i < 6; i++) {
      if (i % 2 == 0) showYellow(200);
      else showOff();
      delay(200);
    }

    brightness = 30;
    showYellow(brightness);
    buttonPressed = false;
  }
}

void showYellow(int b) {
  int r = constrain(b, 0, 255);
  int g = constrain((int)(b * 0.7), 0, 255);
  int bl = 0;
  analogWrite(RledPin, r);
  analogWrite(GledPin, g);
  analogWrite(BledPin, bl);
}

void showRed(int b) {
  analogWrite(RledPin, constrain(b, 0, 255));
  analogWrite(GledPin, 0);
  analogWrite(BledPin, 0);
}

void showOff() {
  analogWrite(RledPin, 0);
  analogWrite(GledPin, 0);
  analogWrite(BledPin, 0);
}

