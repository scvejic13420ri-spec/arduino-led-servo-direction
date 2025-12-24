# arduino-led-servo-direction
This project demonstrates an Arduino-based system with four LEDs, a push button, and a servo motor.

The LEDs light up sequentially in one direction.

A push button is used to reverse the direction of the LED sequence at any moment.

The direction does not change automatically — only the button controls it.

A servo motor is added to track the active LED, moving to a predefined angle for each LED.

When the direction is reversed, the servo follows the LEDs in the opposite direction as well.

The project uses an Arduino Uno, a breadboard, current-limiting resistors, a push button with internal pull-up, and a servo motor.
