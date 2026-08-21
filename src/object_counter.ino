#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize LCD (Address 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin Definitions
const int irSensorPin = 2;    // IR Sensor OUT
const int resetButtonPin = 3; // Push button connected to Pin 3 and GND

// Variables
int objectCount = 0;
bool objectDetected = false;

// Debouncing variables
unsigned long lastTriggerTime = 0;
const unsigned long debounceDelay = 200; // 200ms debounce window

void setup() {
  Serial.begin(9600);
  
  pinMode(irSensorPin, INPUT);
  pinMode(resetButtonPin, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print(" OBJECT COUNTER ");
  lcd.setCursor(0, 1);
  lcd.print(" System Ready!  ");
  delay(1500);

  updateDisplay();
}

void loop() {
  int sensorState = digitalRead(irSensorPin);
  int buttonState = digitalRead(resetButtonPin);
  unsigned long currentTime = millis();

  // 1. Detect Object with Debounce
  if (sensorState == LOW && !objectDetected && (currentTime - lastTriggerTime > debounceDelay)) {
    objectCount++;
    objectDetected = true;
    lastTriggerTime = currentTime;
    
    updateDisplay();
    
    // Serial print for debugging
    Serial.print("COUNT:");
    Serial.println(objectCount);
  }

  if (sensorState == HIGH && objectDetected) {
    objectDetected = false;
  }

  // 2. Physical Button Reset
  if (buttonState == LOW) {
    objectCount = 0;
    updateDisplay();
    
    lcd.setCursor(0, 1);
    lcd.print("RESETTING...    ");
    delay(500); 
    updateDisplay();
  }
}

void updateDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("OBJECT COUNTER");
  
  lcd.setCursor(0, 1);
  lcd.print("Total: ");
  lcd.print(objectCount);
}
