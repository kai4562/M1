// Requirement: ch55xduino https://github.com/DeqingSun/ch55xduino
// Board: CH552 Board
// USB Settings: USER CODE w/ 148B USB ram
// Upload method: USB
// Clock Source: 24MHz (internal) 5V
// Bootloader pin: P3.6

#ifndef USER_USB_RAM
#error "This example needs to be compiled with a USER USB setting"
#endif

#include "src/userUsbHidKeyboard/USBHIDKeyboard.h"

#define BUTTON1_PIN 15

bool button1PressPrev = false;

void setup() {
  USBInit();
  pinMode(BUTTON1_PIN, INPUT_PULLUP);

}

void loop() {
  bool button1Press = !digitalRead(BUTTON1_PIN);
  if (button1PressPrev != button1Press) {
    button1PressPrev = button1Press;
    if (button1Press) {
      Keyboard_press(KEY_RETURN);
    } else {
      Keyboard_release(KEY_RETURN);
    }
  }
  delay(50);  //naive debouncing
}
