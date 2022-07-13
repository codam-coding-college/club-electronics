#include <IRremote.hpp>

#define IR_RECIVE_PIN  A3

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(IR_RECIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
  // put your setup code here, to run once:

}

void loop()
{
  if (IrReceiver.decode())
  {
    Serial.println("Pressed: ");
    Serial.println(IrReceiver.decodedIRData.command);
    IrReceiver.resume(); // Enable receiving of the next value
  }
}
