#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define OUT 8


void setup(){
  pinMode (S0, OUTPUT);
  pinMode (S1, OUTPUT);
  pinMode (S2, OUTPUT);
  pinMode (S3, OUTPUT);
  pinMode (OUT, INPUT);

  digitalWrite (S0, LOW);
  digitalWrite (S1, HIGH);
  
  Serial.begin(9600);
}

 void loop(){
  int red, green, blue, clean;
  int nr, ng, nb;

  
    read_color (&red, &green, &blue, &clean);
    Serial.print ("("); 
    Serial.print (red);
    Serial.print (", ");
    Serial.print (green);
    Serial.print (", ");
    Serial.print (blue);
    Serial.print (", ");
    Serial.print (clean);
    Serial.println (")");
    
    nr = (int)255*1.23*(float)clean/red;
    ng = (int)255*1.18*(float)clean/green;
    nb = (int)255*1.4*(float)clean/blue;

    Serial.print ("NORMALIZED: rgb("); 
    Serial.print (nr);
    Serial.print (", ");
    Serial.print (ng);
    Serial.print (", ");
    Serial.print (nb);
    Serial.println (")");
    Serial.println("");
    delay(1000);
}

//Rotina que le o valor das cores
//Pulse in return an unsigned long with the length of the pulse (in microseconds). 
void read_color(int* red, int* green, int* blue, int* clean){
  /* Red Filter */
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  *red = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);

  /* Green Filter */
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  *green = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
  
  /* Blue Filter */
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  *blue = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);

  /* Clean Filter */
  digitalWrite(S2, HIGH);
  digitalWrite(S3, LOW);
  *clean = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
}

