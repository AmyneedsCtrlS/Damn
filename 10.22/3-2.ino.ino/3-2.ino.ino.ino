const int ledPin = 3;      // LED 接在 D3
const int buttonPin = 2;   // Button 接在 D2

int state = 0;             // 0~3 四種狀態
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  // 共陽極：HIGH = 關燈，先確保關閉
  digitalWrite(ledPin, HIGH);
}

void loop() {
  int reading = digitalRead(buttonPin);

  // 按鈕去彈跳 + 狀態切換
  if (reading == HIGH && lastButtonState == LOW) {
    if (millis() - lastDebounceTime > debounceDelay) {
      state++;
      if (state > 3) {
        state = 0;   // 第 4 下回到恆亮
      }
      lastDebounceTime = millis();
    }
  }
  lastButtonState = reading;

  // LED 狀態控制（共陽極邏輯）
  switch (state) {
    case 0:   // 恆亮
      digitalWrite(ledPin, LOW);   // LOW = 亮
      break;

    case 1:   // 慢閃
      blink(1000);
      break;

    case 2:   // 中速閃
      blink(500);
      break;

    case 3:   // 快閃
      blink(200);
      break;
  }
}

// 共陽極專用閃爍函式
void blink(int interval) {
  digitalWrite(ledPin, LOW);   // 亮
  delay(interval);
  digitalWrite(ledPin, HIGH);  // 滅
  delay(interval);
}
