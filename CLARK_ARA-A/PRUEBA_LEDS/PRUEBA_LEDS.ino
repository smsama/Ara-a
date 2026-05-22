#define LED1 5
#define LED2 18

void setup() {
  // put your setup code here, to run once:
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED1, HIGH);
digitalWrite(LED2, HIGH);
delay(100);
digitalWrite(LED1, LOW);
digitalWrite(LED2, LOW);
delay(100);
}
