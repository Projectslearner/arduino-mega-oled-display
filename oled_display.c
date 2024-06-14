/*
    Project name : OLED Display
    Modified Date: 14-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-mega-oled-display
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  // Initialize the display with 128x64 resolution
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // Clear the display buffer
  display.clearDisplay();

  // Set text size and color
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Print initial message
  display.setCursor(0, 0);
  display.println("Hello, Arduino Mega!");
  display.display(); // Display the message

  delay(2000); // Delay to read the initial message
}

void loop() {
  // Clear previous content
  display.clearDisplay();

  // Print new content
  display.setCursor(0, 0);
  display.println("Arduino Mega");

  // Display current time
  display.setCursor(0, 20);
  display.print("Time: ");
  display.println(millis() / 1000); // Display elapsed time in seconds

  // Display analog input value (example)
  int sensorValue = analogRead(A0);
  display.setCursor(0, 40);
  display.print("Analog Input: ");
  display.println(sensorValue);

  // Display update
  display.display();

  delay(1000); // Update display every 1 second
}
