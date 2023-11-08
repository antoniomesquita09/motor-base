#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

String clockwise = "horario";
String counterclockwise = "anti";

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    Serial.println("Comando recebido: " + command);

    if (command == clockwise) {
      myStepper.step(stepsPerRevolution);
    } else if (command == counterclockwise) {
      myStepper.step(-stepsPerRevolution);
    }
  }

  // delay(500);
}

