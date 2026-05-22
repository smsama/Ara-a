//Botones de estrategias
#define PIN_BOTON_DER 4
#define PIN_BOTON_IZQ 15
#define PULSADO LOW
#define N_PULSADO HIGH
int lectura_Boton_Der;
int lectura_Boton_Izq;

void setup() {
  //Botones
  Serial.begin(9600);
  pinMode(PIN_BOTON_DER, INPUT);
  pinMode(PIN_BOTON_IZQ, INPUT);
}

void loop() {
  lectura_Boton_Der = digitalRead(PIN_BOTON_DER);
  Serial.print("Derecha: ");
  Serial.print(lectura_Boton_Der);

  if (lectura_Boton_Der == PULSADO) {
    Serial.print("|   PULSADO");
  } else {
    Serial.print("|   NO PULSADO");
  }

  lectura_Boton_Izq = digitalRead(PIN_BOTON_IZQ);
  Serial.print(" | Izquierda: ");
  Serial.print(lectura_Boton_Izq);


  if (lectura_Boton_Izq == PULSADO) {
    Serial.println("|   PULSADO");
  } else {
    Serial.println("|   NO PULSADO");
  }
}
