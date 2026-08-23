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

## Challenges Faced
* 1. As I don’t have a deep knowledge of circuits, the first challenge I faced was connections on the bread board. I initially tried connecting the circuit using the knowledge that I learnt in class, but it proved to be futile as I spent almost 75% of my time wondering why my setup was not working. Turns out I had short circuited the circuit and hence it didn't work. I took a step back, referred to a youtube video on how a bread board works and came back to it. I gave the proper connections and there I saw the neon glow from the LCD screen. It's a different kind of joy when something that you build and you troubleshoot finally starts working.
* 2. A rather annoying problem I faced was with my LCD screen. It would often freeze up after it counts the object passing through. Or it would start to show black blocks, for which i had to reupload the code and restart the arduino for it to be fixed
* 3. Another problem was my sensor was not sensing anything. Turns out it has a potentiometer on board that I had to manually change. That affects the sensitivity of the sensor. That was quite interesting.

## My Approach
My approach was to build a reliable counter that can be used in real conveyor-belt and footfall counting systems which minimizes human error.
The brain of this setup was the Arduino Uno R3. This is a microcontroller board that runs C++ code. It reads the input signals from the sensor, increments the count and sends the output to the LCD screen all under a second.
The sensor I used for this project was the FC-51 IR Obstacle Avoidance Sensor. This is an infrared sensor with two LED like bulbs on the front. The clear LED is an IR transmitter and the dark LED is an IR receiver. The transmitter constantly emits invisible infrared light. When an
object passes in front, light bounces back into the receiver and the sensor internally connects its OUT pin straight to ground. This provides information to the arduino that there is an object passing through. This pattern is called active-low logic
The output was displayed on a 16 x 2 LCD Display with the I2C adapter. I used an I2C adapter, because directly connecting it requires at least 6 to 10 digital pins on the Arduino. Using the adapter reduces it to two communications pins.

<img width="4096" height="3072" alt="IMG_20260821_195838429_HDR_PORTRAIT" src="https://github.com/user-attachments/assets/c50215a2-ab32-4c1a-9276-49322d5e6c0a" />

Demo Video Link
https://drive.google.com/file/d/1cN2AucrXBwCTcP9WOnwoILtZOKSKYtQ1/view?usp=drive_link





