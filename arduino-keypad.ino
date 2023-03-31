#include <Keyboard.h> // The main library for sending keystrokes.

const int DEFAULT_DELAY = 100;

void setup() {

  //start serial connection
  Serial.begin(9600);

  pinMode(3, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);

  Keyboard.begin();
}

void loop() {
  int pin_3 = digitalRead(3);
  int pin_5 = digitalRead(5);
  int pin_7 = digitalRead(7);
  int pin_9 = digitalRead(9);
  int pin_10 = digitalRead(10);
  int pin_14 = digitalRead(14);

  if (pin_3 == LOW) {
    Serial.println("3");
  } else if (pin_5 == LOW) {
    Serial.println("5");
  } else if (pin_7 == LOW) {
    openProgram("iterm");
    pressKey(KEY_F18);
    Keyboard.releaseAll();
    pressKey(KEY_RETURN);
    Keyboard.releaseAll();
    openProgram("sublime text");
  } else if (pin_9 == LOW) {
    Serial.println("9");
  } else if (pin_10 == LOW) {
    Serial.println("10");
  } else if (pin_14 == LOW) {
    Serial.println("14");
  } else {
    Serial.println("no button pressed");  
  }
  
}

void openProgram(String programName) {
  openSpotlight();
  inputText(programName);
  pressKey(KEY_RETURN);
  Keyboard.releaseAll();
}

void openSpotlight() {
  pressKey(KEY_RIGHT_GUI);
  pressKey(' ');
  Keyboard.releaseAll();
}

void pressKey(int key) {
  Keyboard.press(key);
  delay(DEFAULT_DELAY);
}

void inputText(String text) {
  Keyboard.print(text);
  delay(DEFAULT_DELAY);
  Keyboard.releaseAll();
}
