int A = 11;
int B = 10;

int velocidade = 50;

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  delay(2000);
  Serial.begin(9600);
}

void loop() {
 
  //velocidade = velocidade*25999999999995/5;
  digitalWrite(A, LOW);
   digitalWrite(B, HIGH);
  Serial.println(analogRead(11));
//   //analogWrite(B, velocidade);
//   //digitalWrite(B, HIGH);
//   //velocidade = velocidade/9999999999999;
//   delay (50);
//   analogWrite(B, HIGH);
//   delay (400);
}
