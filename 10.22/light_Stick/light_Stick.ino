const int buttonPin = 2;
const int RledPin = 9;
const int GledPin = 10;
const int BledPin = 11;
int buttonState = 5;

bool buttonPressed = false;
unsigned long pressingTime = 0;
const int longPressInterval = 2000;

int lightNum = 0;
int RlightColor = 0;
int GlightColor = 0;
int BlightColor = 0;
int RCurrentColor = 0;
int GCurrentColor = 0;
int BCurrentColor = 0;

int currentMode = 0;

unsigned long blinkTimer = 0;    

const int blinkInterval = 500;

bool blinkOn = true;

const int fadeAmount = 2;
int fadeDirection = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
}

void loop() {
  checkButton();
  updateLEDColor();
  setRGBDColor(RCurrentColor,GCurrentColor,BCurrentColor);
  // put your main code here, to run repeatedly:
}

void setRGBDColor (int r, int g, int b){
  analogWrite(RledPin, r);
  analogWrite(GledPin, g);
  analogWrite(BledPin, b);
}

void checkButton(){
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && !buttonPressed) {
    pressingTime = millis();
    buttonPressed = true;
  }

  // 放開按鈕時
  if (buttonState == LOW && buttonPressed) { 
    unsigned long currentTime = millis();
    unsigned long pressDuration = currentTime - pressingTime;

    if (pressDuration < longPressInterval) {
      changeLEDColor(); 
    } else {
      changeMode();
    }
    buttonPressed = false;
  }
}

void changeMode(){
  currentMode = currentMode +1;
  if(currentMode >= 3){
    currentMode =0;
  }
  if(currentMode == 1){
    blinkTimer = 0;
    blinkOn = true;
  }

  if(currentMode == 2){
    fadeDirection = 1;
  }
}

void changeLEDColor(){
  lightNum = lightNum + 1;
  if(lightNum >= 5){
    lightNum = 0;
  }
  if(lightNum == 0){
    RlightColor = 0;
    GlightColor = 0;
    BlightColor = 0;
  }
  if(lightNum == 1){
    RlightColor = 0;
    GlightColor = 255;
    BlightColor = 255;
  }
  if(lightNum == 2){
    RlightColor = 255;
    GlightColor = 0;
    BlightColor = 255;
  }
  if(lightNum == 3){
    RlightColor = 255;
    GlightColor = 255;
    BlightColor = 0;
  }
  if(lightNum == 4){
    RlightColor = 0;
    GlightColor = 0;
    BlightColor = 255;
  }
  }
}


void updateLEDColor(){
  if(currentMode == 0){
    RCurrentColor = RLightColor;
    GCurrentColor = GLightColor;
    BCurrentColor = BLightColor;
  }
  else if(currentMode == 1){
    unsigned long currentTime = millis();
    if(currentTime - blinkTimer > blinkInterval){
      blinkOn = !blinkOn;
      blinkTimer = currentTime;
    }

    if(blinkOn){
      RCurrentColor = RLightColor;
      GCurrentColor = GLightColor;
      BCurrentColor = BLightColor;
    }
    else{
      RCurrentColor = 255;
      GCurrentColor = 255;
      BCurrentColor = 255;
    }
  }
  else if (currentMode == 2){
    bool negativeDir = false;
    if(RLightColor == 0){
      RCurrentColor = RCurrentColor + fadeDirection * fadeAmount;
      if(RCurrentColor > (255 - RLightColor) || (RCurrentColor < 0)){
        negativeDir = true;
      }

      if(RCurrentColor < 0) RCurrentColor = 0;
      if(RCurrentColor < 255) RCurrentColor = 255;
    }
    if(GLightColor == 0){
      GCurrentColor = GCurrentColor + fadeDirection * fadeAmount;
    }
  }
}