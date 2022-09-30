#include <Stepper.h>
const int pasosStepperRevoluciones = 2048;
Stepper myStepper(pasosStepperRevoluciones, 8, 10, 9, 11);
const int pot = A0;
int cantidad = 1000;
int cantPasos = pasosStepperRevoluciones / cantidad;

void setup() {
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop() {
  int valPot = analogRead(pot);
  int velocidadPot = map(valPot, 0, 1023, 0, 20);
  Serial.println(velocidadPot);
  if (velocidadPot > 0) {
    myStepper.setSpeed(velocidadPot);
    myStepper.step(cantPasos);
  }
}
