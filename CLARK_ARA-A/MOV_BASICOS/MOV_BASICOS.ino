#include <ESP32Servo.h>

int posicion = 0;
bool sumar = true;


// Define 8 Servos
Servo upFrontIzq;   // Subir servo de adelante a la izquierda
Servo movFrontIzq;  // Mover servo de adelante a la izquierda
#define UP_FRONT_IZQ 32
#define MOV_FRONT_IZQ 33


Servo upBackIzq;   //Subir servo de atrás a la izquierda
Servo movBackIzq;  // Mover servo de atrás a la izquierda
#define UP_BACK_IZQ 25
#define MOV_BACK_IZQ 26


Servo upFrontDer;   // Subir servo de adelante a la derecha
Servo movFrontDer;  // Mover servo de adelante a la derecha
#define UP_FRONT_DER 27
#define MOV_FRONT_DER 14


Servo upBackDer;   // Subir servo de atras a la derecha
Servo movBackDer;  // Mover servo de atras a la derecha
#define UP_BACK_DER 12
#define MOV_BACK_DER 13

// Giros y posiciones utilizados
#define RESET_POSITION 0
//Experimentally, 550 and 2350 are pretty close to 0 and 180.

// Tiempo
#define PAUSE 2000

ESP32PWM pwm;
int upFrontIzqPin = 15;
int movFrontIzqPin = 12;
int minUs = 1000;
int maxUs = 2000;

void setup() {
  // Attach servos to Arduino Pins
  Serial.begin(115200);
  upFrontIzq.attach(UP_FRONT_IZQ, minUs, maxUs);
  movFrontIzq.attach(MOV_FRONT_IZQ, minUs, maxUs);

  upBackIzq.attach(UP_BACK_IZQ, minUs, maxUs);
  movBackIzq.attach(MOV_BACK_IZQ, minUs, maxUs);

  upFrontDer.attach(UP_FRONT_DER, minUs, maxUs);
  movFrontDer.attach(MOV_FRONT_DER, minUs, maxUs);

  upBackDer.attach(UP_BACK_DER, minUs, maxUs);
  movBackDer.attach(MOV_BACK_DER, minUs, maxUs);

  centrar();
}

void loop() {
 centrar();
}

void centrar() {
  upFrontIzq.write(RESET_POSITION);
  movFrontIzq.write(RESET_POSITION);
  delay(20);

  upBackIzq.write(RESET_POSITION);
  movBackIzq.write(0);
  delay(20);

  upFrontDer.write(RESET_POSITION);
  movFrontDer.write(RESET_POSITION);
  delay(20);

  upBackDer.write(RESET_POSITION);
  movBackDer.write(RESET_POSITION);
  delay(20);
}

void mover() {
  upFrontIzq.write(posicion);
  movFrontIzq.write(posicion);
  delay(20);

  upBackIzq.write(posicion);
  movBackIzq.write(posicion);
  delay(20);

  upFrontDer.write(posicion);
  movFrontDer.write(posicion);
  delay(20);

  upBackDer.write(posicion);
  movBackDer.write(posicion);
  delay(20);
}

void moveLegServos_Forward() {
  // Control the servo actions for each leg
  // Left side leg - Leg 1
  //Serial.print("left");
  moveLeg_Left_Forward(upBackIzq, movBackIzq, upBackIzq);
  // Left side leg - Leg 4
  //moveLeg_Left_Forward(upFrontIzq, movFrontIzq, upFrontIzq);
  //Serial.println(";");
  // Left side leg - Legs 1 and 4
  for (int angle = 0; angle <= 90; angle += 2) {
    //movBackDer.write(angle);
    //movFrontIzq.write(angle);
    //delay(10);
  }
  // Right side leg - Leg 2
  //Serial.print("right");
  /*
  moveLeg_Right_Forward(upFrontDer, movFrontDer, upFrontDer);
  moveLeg_Right_Forward(upBackDer, movBackDer, upBackDer);
  Serial.println(";");
  // Right side leg - Legs 2 and 3
  for (int angle = 180; angle >= 90; angle -= 2) {
    movFrontDer.write(angle);
    movBackIzq.write(angle);
    delay(10);
  }
  */
  // Right side leg - Leg 3
}  

void moveLeg_Left_Forward(Servo& liftServo, Servo& pivotServo , Servo& oppositePivotServo) {
  // Move the lift servo from 90 to 180
  for (int angle = 90; angle <= 180; angle += 2) {
    liftServo.write(angle);
    delay(10);
  }
  // Move the pivot servo from 90 to 0
  for (int angle = 90; angle >= 0; angle -= 2) {
    pivotServo.write(angle);
    delay(10);
    Serial.println("pivot");
  }
  // Move the lift servo from 180 to 90
  for (int angle = 180; angle >= 90; angle -= 2) {
    liftServo.write(angle);
    Serial.println("lift");
    delay(10);
  }
}
void moveLeg_Right_Forward(Servo& liftServo, Servo& pivotServo , Servo& oppositePivotServo) {
  // Move the lift servo from 90 to 180
  for (int angle = 90; angle <= 180; angle += 2) {
    liftServo.write(angle);
    delay(10);
  }
  // Move the pivot servo from 90 to 180
  for (int angle = 90; angle <= 180; angle += 2) {
    pivotServo.write(angle);
    delay(10);
  }
  // Move the lift servo from 180 to 90
  for (int angle = 180; angle >= 90; angle -= 2) {
    liftServo.write(angle);
    delay(10);
  }
}
        // Move Spider  Robot Backward logic
void moveLeg_Left_Backward(Servo& liftServo, Servo& pivotServo, Servo& oppositePivotServo) {
  // Move the lift servo from 90 to 180
  for (int angle = 90; angle <= 180; angle += 2) {
    liftServo.write(angle);
    delay(10);
  }
  // Move the pivot servo from 90 to 180
  for (int angle = 90; angle <= 180; angle += 2) {
    pivotServo.write(angle);
    delay(10);
  }
  // Move the lift servo from 180 to 90
  for (int angle = 180; angle >= 90; angle -= 2) {
    liftServo.write(angle);
    delay(10);
  }
}
void moveLeg_Right_Backward(Servo& liftServo, Servo& pivotServo, Servo& oppositePivotServo) {
  // Move the lift servo from 90 to 180
  for (int angle = 90; angle <= 180; angle += 2) {
    liftServo.write(angle);
    delay(10);
  }
  // Move the pivot servo from 90 to 0
  for (int angle = 90; angle >= 0; angle -= 2) {
    pivotServo.write(angle);
    delay(10);
  }
  // Move the lift servo from 180 to 90
  for (int angle = 180; angle >= 90; angle -= 2) {
    liftServo.write(angle);
    delay(10);
  }
}