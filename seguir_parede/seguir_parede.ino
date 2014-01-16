void move_m(int md,int me){ 
  //Ordem para os motores
  digitalWrite(4,HIGH); 
  digitalWrite(7,LOW);
  analogWrite( 5, me); 
  analogWrite( 6, md);     
}

void move_t(int md,int me,int t)
{  //Ordem para os motores com tempo
  move_m(md,me);  delay(t);
  move_m(0,0);
}


void setup()  { 
  Serial.begin(9600);
  //Declarar Portas dos Motores
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);pinMode(5, OUTPUT);     
  pinMode(6, OUTPUT);pinMode(7, OUTPUT);     
} 

int medir()
{
}

void loop()
{

  int threshold=10;\\MFV++ distância da parede pretendida 
  
  int duration, distance;
  digitalWrite(2, HIGH);
  delayMicroseconds(1000);
  digitalWrite(2, LOW);
  duration = pulseIn(3, HIGH);
  distance = (duration/2) / 29.1;
  
  
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
    move_m(80,80);
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    //MFV++ se a distância se manter, segue em frente
    if (distance = threshold){
        move_m(80,80);
        }
    else 
    if (distance > threshold){
        move_m(0,80);
        }
    else{
        move_m(80,0);
        
    }
  }
  delay(100);
}
