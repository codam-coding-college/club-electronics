/*
 * IR_LED_Controller
 * 
 * Preparations:
 * Connect 3 LEDs to digital pins 2, 3 and 4
 * Connect IR_receiver to pin A3
 * 
 * Install IRremote library
 */

#include <IRremote.hpp>

#define IR_RECIVE_PIN  A3 // pin of ir receiver

const int leds[] = {2, 3, 4}; // led pins
boolean ledStates[] = {0, 0, 0}; // initial led States. all 0
const int num_leds = 3; // amount of connected pins

int lightMode = 0;

unsigned long previousMillis = 0;
int interval = 100; // speed to update the party mode

int lastCommand = 0;

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(IR_RECIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
  // put your setup code here, to run once:
  for (int i = 0; i < num_leds; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
}

void loop()
{
  unsigned long currentMillis = millis();
  
  if (IrReceiver.decode())
  {
    int command = IrReceiver.decodedIRData.command;
    Serial.println("Pressed: ");
    Serial.println(command);
    if (command != lastCommand)
    {
      commandCenter(command);
      lastCommand = command;
    }
    IrReceiver.resume(); // Enable receiving of the next value
  }
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    update_lights(lightMode);
  }
}

//translate the input command to a lightMode
void  commandCenter(int command)
{
  switch(command) {
    case 82:
      lightMode = 0;
      break;
    case 22:
      lightMode = 1;
      break;
    case 25:
      lightMode = 2;
      break;
    default:
      return;
  }
}

//based on the lightMode update the light
void  update_lights(int command)
{
  switch(command) {
    case 0:
      turn_off();
      break;
    case 1:
      cozy_lighting();
      break;
    case 2:
      party_mode();
      break;
    default:
      return;
  }
  delay(300);
}

// change led state. If it was on, turn it off and vice versa
void  toggle_led(int led)
{
  ledStates[led] = 1 - ledStates[led];
  digitalWrite(leds[led], ledStates[led]);
}

// only yellow light
void cozy_lighting()
{
    for (int i = 0; i < num_leds; i++)
    {
      if ((ledStates[i] == 1 && i != 1) || (ledStates[i] == 0 && i == 1))  
        toggle_led(i);
    }
}

// random colors
void party_mode()
{
  int count = 0;

  // toggle a random led
  toggle_led(random(0, num_leds));
  
  // count how many leds are on
  for (int i = 0; i < num_leds; i++)
    count += ledStates[i];

  // if no leds are on, turn on one random led
  if (count == 0)
    toggle_led(random(0, num_leds));
}

// turn all leds off
void turn_off()
{
  for (int i = 0; i < num_leds; i++)
  {
    if (ledStates[i] == 1)
      toggle_led(i);
  }
}
