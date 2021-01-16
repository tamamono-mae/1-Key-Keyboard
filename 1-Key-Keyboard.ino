#define BUTTON_PIN 2
#include "Keyboard.h"

bool state = false;
bool button_state = true;
bool last_button_state = true;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Keyboard.begin();
  //Serial.begin(115200);
}

void loop() {
  if (button_falling_edge(&button_state, &last_button_state)) {
	Keyboard.press(KEY_F10);
	delay(5);
	Keyboard.releaseAll();
	delay(95);
  } else delay(10);

}

bool button_falling_edge(bool *bs , bool *lbs){
	*bs = (digitalRead(BUTTON_PIN) == HIGH);
	if (*lbs && !*bs){
		*lbs = false;
		return true;
	}
	else{
		*lbs = *bs;
		return false;
	}
}
