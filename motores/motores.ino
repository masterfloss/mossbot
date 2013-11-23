//Standard PWM DC control
int E1 = 5;     //Controlo de velocidade de M1 
int E2 = 6;     //Controlo de velocidade de M2 
int M1 = 4;    //Controlo de direcção de M1 
int M2 = 7;    //Controlo de direcção de  M1 
 
void stop(void){
//Stop
  digitalWrite(E1,LOW);  
  digitalWrite(E2,LOW);     
}  

//
//controlo de velocidade por PWM

void virar_D(int a,int b) {
  analogWrite (E1,a);      
  digitalWrite(M1,HIGH);   
  analogWrite (E2,b);   
  digitalWrite(M2,HIGH);

} 

 //
void virar_E(int a,int b) {
  analogWrite (E1,a);
  digitalWrite(M1,LOW);  
  analogWrite (E2,b);   
  digitalWrite(M2,LOW);
  
}

//
void andar_T (int a,int b) {
  analogWrite (E1,a);
  digitalWrite(M1,LOW);   
  analogWrite (E2,b);   
  digitalWrite(M2,HIGH);

}

//
void andar_F (int a,int b){
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);   
  analogWrite (E2,b);   
  digitalWrite(M2,LOW);
  
}

// iniciar
// Define taxa de tansmissão (Baud Rate)
void setup(void){
  int i;
  for(i=4;i<=7;i++)
    pinMode(i, OUTPUT); 
  Serial.begin(19200);      
  Serial.println("Iniciar");
}

// ciclo principal 
void loop(void){
  // exemplo -virar a direita"
  virar_E (100,100);
 
}
