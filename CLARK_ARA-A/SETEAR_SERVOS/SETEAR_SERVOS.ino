#include <ESP32Servo.h>

// Define 8 Servos
Servo upFrontIzq;   // Subir servo de adelante a la izquierda
Servo movFrontIzq;  // Mover servo de adelante a la izquierda
#define UP_FRONT_IZQ 13
#define MOV_FRONT_IZQ 12

Servo upBackIzq;   //Subir servo de atrás a la izquierda
Servo movBackIzq;  // Mover servo de atrás a la izquierda
#define UP_BACK_IZQ 14
#define MOV_BACK_IZQ 27

Servo upFrontDer;   // Subir servo de adelante a la derecha
Servo movFrontDer;  // Mover servo de adelante a la derecha
#define UP_FRONT_DER 26
#define MOV_FRONT_DER 25

Servo upBackDer;   // Subir servo de atras a la derecha
Servo movBackDer;  // Mover servo de atras a la derecha
#define UP_BACK_DER 33
#define MOV_BACK_DER 32

#define RESET_POSITION 90

void setup() {
  // Attach servos to Arduino Pins
  upFrontIzq.attach(UP_FRONT_IZQ);
  movFrontIzq.attach(MOV_FRONT_IZQ);
  upFrontIzq.write(RESET_POSITION);
  movFrontIzq.write(RESET_POSITION);

  upBackIzq.attach(UP_BACK_IZQ);
  movBackIzq.attach(MOV_BACK_IZQ);
  upBackIzq.write(RESET_POSITION);
  movBackIzq.write(RESET_POSITION);

  upFrontDer.attach(UP_FRONT_DER);
  movFrontDer.attach(UP_FRONT_DER);
  upFrontDer.write(RESET_POSITION);
  movFrontDer.write(RESET_POSITION);

  upBackDer.attach(UP_BACK_DER);
  movBackDer.attach(UP_BACK_DER);
  upBackDer.write(RESET_POSITION);
  movBackDer.write(RESET_POSITION);
}
void loop() {
}