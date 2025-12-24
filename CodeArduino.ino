#include <Servo.h>

const int leds[] = {6, 9, 10, 11};
const int ledCount = 4;

const int buttonPin = 4;
const int servoPin = 3;

int currentLed = 0;
int direction = 1;

bool lastButtonState = HIGH;

Servo myServo;

// Uglovi serva za svaku LED
int servoAngles[] = {0, 60, 120, 180};

void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(leds[i], OUTPUT);
  }

  pinMode(buttonPin, INPUT_PULLUP);

  myServo.attach(servoPin);
  myServo.write(servoAngles[currentLed]);
}

void loop() {
  // ---- Dugme ----
  bool buttonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && buttonState == LOW) {
    direction = -direction;
    delay(50); // kratki debounce
  }
  lastButtonState = buttonState;

  // ---- LED ----
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(leds[i], LOW);
  }

  digitalWrite(leds[currentLed], HIGH);

  // ---- SERVO PRATI LED ----
  myServo.write(servoAngles[currentLed]);

  delay(300);

  currentLed += direction;

  if (currentLed >= ledCount) currentLed = 0;
  if (currentLed < 0) currentLed = ledCount - 1;
}
