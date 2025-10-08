/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/
const int buttonPin = 2;
const int Rledpin = 3;
const int Gledpin = 4;
const int Bledpin = 5;

int buttonState = 0;
int ledState = LOW;
int ledcolor = 0;
bool ButtonPressed = false;
String currentcolor = "led";
unsigned long previousMillis = 0;
const long interval = 1000;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(Rledpin, OUTPUT);
  pinMode(Gledpin, OUTPUT);
  pinMode(Bledpin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  buttonState = digitalRead(buttonPin);
  Serial.print("Current color: ");
  Serial.println(currentcolor);
  if(buttonState == HIGH && !ButtonPressed){
    ledcolor = ledcolor + 1;
    ButtonPressed = true;
  }
  if(buttonState == LOW && ButtonPressed){
    ButtonPressed = false;
  }
  unsigned long currentMillis = millis();
if (currentMillis - previousMillis >= interval) {
  previousMillis = currentMillis;
if (ledState == LOW){
  ledState == HIGH;
}else {
  ledState = LOW;
}
}
if (ledcolor == 0){
  currentcolor = "LED off";
  digitalWrite(Rledpin, HIGH);
  digitalWrite(Gledpin, HIGH);
  digitalWrite(Bledpin, HIGH);
}
else if (ledcolor == 1){
  currentcolor = "Red";
  if (ledState ==LOW){
  digitalWrite(Rledpin, LOW);
  digitalWrite(Gledpin, HIGH);
  digitalWrite(Bledpin, HIGH);
  }else{
  digitalWrite(Rledpin, HIGH);
  digitalWrite(Gledpin, HIGH);
  digitalWrite(Bledpin, HIGH);
  }
}
else if (ledcolor == 2){
  currentcolor = "Green";
  if (ledState ==LOW){
  digitalWrite(Rledpin, HIGH);
  digitalWrite(Gledpin, LOW);
  digitalWrite(Bledpin, HIGH);
  }else{
  digitalWrite(Rledpin, HIGH);
  digitalWrite(Gledpin, HIGH);
  digitalWrite(Bledpin, HIGH);
  }
}
else if (ledcolor == 3){
  currentcolor = "Blue";
  if (ledState ==LOW){
  digitalWrite(Rledpin, HIGH);
  digitalWrite(Gledpin, HIGH);
  digitalWrite(Bledpin, LOW);
  }else{
  digitalWrite(Rledpin, HIGH);
  digitalWrite(Gledpin, HIGH);
  digitalWrite(Bledpin, HIGH);
  }
}
else if (ledcolor == 4){
  currentcolor = "Yellow";
  if (ledState ==LOW){
  digitalWrite(Rledpin, LOW);
  digitalWrite(Gledpin, LOW);
  digitalWrite(Bledpin, HIGH);
  }else{
  digitalWrite(Rledpin, HIGH);
  digitalWrite(Gledpin, HIGH);
  digitalWrite(Bledpin, HIGH);
  }
}
else if (ledcolor == 5){
  currentcolor = "Purple";
  if (ledState ==LOW){
  digitalWrite(Rledpin, LOW);
  digitalWrite(Gledpin, HIGH);
  digitalWrite(Bledpin, LOW);
  }else{
  digitalWrite(Rledpin, HIGH);
  digitalWrite(Gledpin, HIGH);
  digitalWrite(Bledpin, HIGH);
  }
}
else if (ledcolor == 6){
  currentcolor = "Cyan";
  if (ledState ==LOW){
  digitalWrite(Rledpin, HIGH);
  digitalWrite(Gledpin, LOW);
  digitalWrite(Bledpin, LOW);
  }else{
  digitalWrite(Rledpin, HIGH);
  digitalWrite(Gledpin, HIGH);
  digitalWrite(Bledpin, HIGH);
  }
}
else if (ledcolor == 7){
  currentcolor = "White";
  if (ledState ==LOW){
  digitalWrite(Rledpin, LOW);
  digitalWrite(Gledpin, LOW);
  digitalWrite(Bledpin, LOW);
  }else{
  digitalWrite(Rledpin, HIGH);
  digitalWrite(Gledpin, HIGH);
  digitalWrite(Bledpin, HIGH);
  }
}
else if(ledcolor ==8){
  ledcolor =0;
}
}

