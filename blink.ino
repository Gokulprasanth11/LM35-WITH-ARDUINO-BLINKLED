
#include <RBD_Timer.h> // https://github.com/alextaujenis/RBD_Timer- Include the RBD_Timer library
#include <RBD_Light.h> // https://github.com/alextaujenis/RBD_Light- Include the RBD_Light library

int blinkless = 250;   // Duration of the blink for temperatures below 30 degrees Celsius (in milliseconds)
int blinkMore = 500;   // Duration of the blink for temperatures above 30 degrees Celsius (in milliseconds)
int blinkLed = 13;     // Pin number to which the LED is connected
RBD::Light light(blinkLed);  // Create an instance of the RBD::Light class to control the LED

void setup() {
  Serial.begin(9600);   // Initialize serial communication at 9600 baud rate
}

void loop() {
  int analogValue = analogRead(A0);   // Read the analog value from pin A0 connected to the temperature sensor
  float celsius = (analogValue * 500.) / 1023.;  // Convert the analog value to Celsius temperature

  Serial.print("Temperature: ");   // Print the temperature label
  Serial.print(celsius);            // Print the temperature value
  Serial.println(" ℃");             // Print the temperature unit
  
  if (celsius < 30) {   // If the temperature is below 30 degrees Celsius
    light.blink(blinkless, blinkless);  // Blink the LED with the specified duration
    light.update();   // Update the LED state
  } 
  else if (celsius > 30) {   // If the temperature is above 30 degrees Celsius
    light.blink(blinkMore, blinkMore);  // Blink the LED with a different duration
    light.update();   // Update the LED state
  }
}

