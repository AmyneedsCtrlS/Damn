const int Rledpin = 9;
const int Gledpin = 10;
const int Bledpin = 11;
int maxBrightness = 0;
int currentBrightness = 0;
int fadingDirection =1;
unsigned long previousMillis = 0;
int interval = 1000;
void setup() {
  // put your setup code here, to run once:
  pinMode(Rledpin, OUTPUT);
  pinMode(Gledpin, OUTPUT);
  pinMode(Bledpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  maxBrightness = 255;
  unsigned long currentMillis = millis();
  int fadingAmount = fadingDirection = map(currentMillis - previousMillis,0,interval, 0,maxBrightness);
  currentBrightness = currentBrightness + fadingAmount;
  if(currentBrightness >= 255){
    currentBrightness = 255;
    fadingDirection = -fadingDirection;
  }
  if(currentBrightness <= 0){
    currentBrightness = 0;
    fadingDirection = -fadingDirection;
  }
  analogWrite(Rledpin, currentBrightness);
  analogWrite(Gledpin, currentBrightness);
  analogWrite(Bledpin, currentBrightness);
  previousMillis = currentMillis;
  delay(1);
}
