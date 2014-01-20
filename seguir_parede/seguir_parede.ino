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

  int safe_distance=20;\\MFV++ distância da parede pretendida
  int perfect_distance=18;\\MFV++ distância da parede pretendida 
  int min_distance=15;\\MFV++ distância da parede pretendida 
  
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
    //MFV++ se a distância estiver no range pretendido, segue em frente
    if (distance = perfect_distance){
        move_m(80,80);
        }
    else 
    //MFV++ vira rápido, está muito perto
    if (distance < min_distance){
        move_m(0,80);
        }
    else{
    //MFV++ vira, mas sem pressa
    if (distance <  safe_distance){
        move_m(20,80);
        }
    else{
    //MFV++ vira rápido, está muito longe
    if (distance >  safe_distance + min_distance){
        move_m(80,00);
        }
    else{
        move_m(80,20);
        
    }
  }
  delay(100);
}
