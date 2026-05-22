const int PIN_TRIG = 34;
const int PIN_ECHO = 35;
int lecturaSensorDist = 0;  


void setup()
{
pinMode(PIN_TRIG, OUTPUT);
pinMode(PIN_ECHO, OUTPUT);
digitalWrite(PIN_TRIG, LOW);

Serial.begin(9600);
}


void loop()
{
digitalWrite(PIN_TRIG, HIGH);
digitalWrite(PIN_ECHO, HIGH);
/*
lecturaSensorDist = SensorDist(PIN_TRIG,PIN_ECHO);
Serial.print("Distancia: ");
Serial.print(lecturaSensorDist);      //Enviamos serialmente el valor de la distancia
Serial.println("cm");
*/
}


int SensorDist (int TRIGGER, int ECHO)
{
  long tiempo; //tiempo que demora en llegar el echo
  long distance; //distancia en centimetros


  //digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  //digitalWrite(TRIGGER, LOW);


  tiempo = pulseIn(ECHO, HIGH); //obtenemos el ancho del pulso
  distance = tiempo / 59;           //escalamos el tiempo a una distancia en cm


  return (distance);
}
