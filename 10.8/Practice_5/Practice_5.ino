const int Rledpin = 9;
const int Gledpin = 10;
const int Bledpin = 11;
int brightness = 0;
int fadeAmount = 5;
int ledcolor = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(Rledpin, OUTPUT);
  pinMode(Gledpin, OUTPUT);
  pinMode(Bledpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(ledcolor == 0){
    analogWrite(Rledpin, brightness);
    analogWrite(Gledpin, 255);
    analogWrite(Bledpin, 255);
  }
  if(ledcolor == 1){
    analogWrite(Rledpin, 255);
    analogWrite(Gledpin, brightness);
    analogWrite(Bledpin, 255);
  }
  if(ledcolor == 2){
    analogWrite(Rledpin, 255);
    analogWrite(Gledpin, 255);
    analogWrite(Bledpin, brightness);
  }
  brightness = brightness + fadeAmount;

  if(brightness <= 0 || brightness >= 255){
    fadeAmount = -fadeAmount;
    if(brightness >= 255){
      ledcolor = ledcolor +1;
      if(ledcolor > 2){
        ledcolor =0;
      }
    }
  }
  delay(30);
}
