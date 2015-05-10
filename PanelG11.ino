/* @file PanelG11.ino
|| @version 1.0
|| @author Florin Tanasa
|| @contact florin.tanasa@gmail.com
||
|| @description
||  | Matrix keypad for G11 SDR Panel
||  | for teensy 2.0 set Tools->USB type->serial+keyboard+mouse+joystick
|| #
*/
#include <Keypad.h>

/*
160m  80m        60m          Up_filter
 40m  30m        20m          Down_filter
 17m  15m        12m          Step_freq_up
 10m  Mode_left  Mode_right   Step_freq_down
*/

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {KEY_0,  KEY_1,       KEY_2,        KEY_PAGE_UP},
  {KEY_3,  KEY_4,       KEY_5,        KEY_PAGE_DOWN},
  {KEY_6,  KEY_7,       KEY_8,        KEY_UP},
  {KEY_9,  KEY_COMMA,	KEY_PERIOD,   KEY_DOWN}
};
byte rowPins[ROWS] = {3, 2, 1, 0}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600); //maybe for the future to read input voltage
  keypad.setDebounceTime(20); //set debounce in ms
  keypad.setHoldTime(500); //set hold time in ms
}

void loop() {
   char key = keypad.getKey(); //read the keys
   KeyState state = keypad.getState();//read the state of the keys
 
  if(key && (state == PRESSED || state == HOLD ))
  Keyboard.set_key1(key);
  if (state == RELEASED)
  Keyboard.set_key1(0);
  
  Keyboard.send_now();
}

