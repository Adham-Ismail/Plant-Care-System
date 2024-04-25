#include <Servo.h>

Servo myServo;
int fpgaSignalPin = 8;   // Pin connected to the FPGA signal
int servoControlPin = 9; // Pin connected to the servo motor

void setup() {
  myServo.attach(servoControlPin); // Attaching the servo to its control pin
  pinMode(fpgaSignalPin, INPUT);   // Setting the pin connected to the FPGA signal as input
}

void loop() {
  // Read the signal from the FPGA
  int fpgaSignal = digitalRead(fpgaSignalPin);

  if (fpgaSignal == HIGH) {
    // If the signal from the FPGA was received, rotate the servo motor
    myServo.write(180); // Rotate the servo to 180 degrees
    delay(1000);        // Wait for 1 second

    myServo.write(0);   // Rotate the servo back to 0 degrees
    delay(1000);        // Wait for 1 second
  }
}