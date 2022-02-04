/*Final project 2019
  Paper Code : ENEL599
  Student: Leegan Te, ID: 16961403
  This program gives a command for the code to run a countdown timer
  which makes the three leds go off and the buzzer to tell the time is up.
  There are three buttons, one which is a start button, reset, and add button.
*/
#include "Wire.h" // For I2C
#include "LCD.h" // For LCD
#include "LiquidCrystal_I2C.h" // Added library*
#include <time.h>

//Set the pins on the I2C chip used for LCD connections
//ADDR,EN,R/W,RS,D4,D5,D6,D7
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7); // 0x27 is the default I2C bus address of the backpack-see article

int buzzer = 13;
int redLED = 9;
int greenLED = 12;
int yellowLED = 11;

float timer;
float seconds;
int minutes;

int reset_button = 5;
int add_button = 8;
int start_button = 6;

int buttonstate_pressed = LOW;
int buttonstate2_pressed = LOW;
int buttonstate3_pressed = LOW;
int buttonstate;
int buttonstate2;
int buttonstate3;

int config = 2;
void setup()
{
  pinMode(reset_button, INPUT_PULLUP);
  pinMode(start_button, INPUT_PULLUP);
  pinMode(add_button, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  // initialize the LCD
  lcd.begin(16, 2);
  lcd.setBacklightPin(3, POSITIVE); // BL, BL_POL
  lcd.setBacklight(HIGH);
  // Turn on the blacklight and print a message.
  lcd.backlight();
  //lcd.home();
  lcd.setCursor(0, 0);
  lcd.print("BOMB TIMER :D :"); //prints the writing inside the qoute marks on the lcd screen

  seconds = 0; // starts up the systems with a zero
}

void loop()
{
  //minutes++;

  //reads the pushbuttons input pin
  buttonstate = digitalRead(add_button);
  buttonstate2 = digitalRead(reset_button);
  buttonstate3 = digitalRead(start_button);

  if (buttonstate != buttonstate_pressed)
  {
    buttonstate_pressed = buttonstate;

    // if the state has changed, decrease the counter
    if (buttonstate == LOW)
      digitalWrite(redLED, HIGH);
    {
      seconds ++;  // once the button has been pressed number goes up by 1.
      seconds >= 0;
      {
        digitalWrite(redLED, HIGH);
        delay(10); //the delay pauses the program for a certain amount of time
      }
    }
  }
  if (buttonstate2 == LOW)
  {
    seconds = 0 ;
    {
      digitalWrite(greenLED, HIGH);
      delay(10);               // delay, pauses the program for a certian amount of time
    }
  }

  lcd.setCursor(0, 1);
  lcd.print(seconds);

  {
    if (buttonstate3 == LOW)
    {
     // timer = 60/3600;
     // seconds = 60/3600, timer--;
      
      //= minutes;
if (seconds == 0)
      {
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
      }
      else
      {
        seconds--;
        delay(1000);
      }
      // pinMode(buzzer, HIGH);
    }
  }
  digitalWrite(yellowLED, HIGH);
}
