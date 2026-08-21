# Automated IR Object Counter with LCD & Reset Button

An automated object counting system built using an Arduino Uno, an IR obstacle avoidance sensor, an I2C 16x2 LCD display, and a physical reset push button.

---

##  Project Overview
Manual object counting in entryways or assembly lines is prone to human error. This system automates real-time counting using infrared reflection and presents live feedback on an I2C LCD screen while offering a dedicated tactile reset mechanism.

---

##  Components Used
* **Microcontroller:** Arduino Uno R3
* **Sensor:** FC-51 IR Obstacle Avoidance Sensor
* **Display:** 16x2 I2C LCD Display (Address: `0x27`)
* **Control:** Push Button (Internal Pull-Up configured)
* **Breadboard & Jumper Wires**


##  Challenges Faced & Solutions
1. **Signal Debouncing:** Rapid/flickering object movements caused double-counting. Solved using non-blocking software debouncing with `millis()`.
2. **I2C LCD Initialization:** Encountered compilation and block display issues, resolved by validating the address (`0x27`) and including proper Wire libraries.

---

##  Future Scope
* Adding ESP32/Wi-Fi support to push count data live to a web app or cloud database.
* Integrating a buzzer module for audio feedback on every increment.
