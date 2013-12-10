// MFV++ 
// MOSSBot
// 

//Parâmetros do MOSSBot
const int SafeDistance = 15; //centímetros
const int LoopCicleDelay = 20; //milisegundos

bool turningLeft = false;
bool turningRight = false;

//Standard PWM DC control
int E1 = 5;     //Controlo de velocidade de M1 
int E2 = 6;     //Controlo de velocidade de M2 
int M1 = 4;    //Controlo de direcção de M1 
int M2 = 7;    //Controlo de direcção de  M1 

#define trigPin 2
#define echoPin 3

//MFV++ Configurações do MOSSBot
void setup() 
{ 
  Serial.begin(9600);
  
  //ultrasom
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  //Declarar Portas dos Motores
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);     
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);  	
} 

//MFV++ Deverá passar a classe própria
int DecideBestDirection()
{
  // MFV++
  // Verifica a distância
  // a que se encontra de possíveis obstáculos
  int distance = medir_dist();;
  Serial.print("Distância actual = ");
  Serial.print(distance);
  
  //MFV++ distância de segurança 
  if(distance < SafeDistance)
  {
	//valida se já está a virar para algum lado
	if (turningLeft)
		virar_E(100,100);
	else if (turningRight)
		//continua a virar à direita
		virar_D(100,100);
	else
	{
		//TODO: invocar motor pára
		//parar motor
		stop();
		 
		//se tiver servo no futuro, poderemos validar se temos obstáculo à esquerda ou à direita e escolher
		//para já vira para um lado qualquer
		 
		if(random(100) > 50)
		{
			//vira à direita
			turningRight = true;
		    	turningLeft = false;
		    	virar_D(100,100);
			Serial.println("Vira à direita");
		}
		else
		{
		    //vira à esquerda
		    turningLeft = true;
		    turningRight = false;
		    virar_E(100,100);
	            Serial.println("Vira à esquerda");
		  }
		}
	}
	else
	{
		turningLeft = false;
		turningRight = false;
		andar_F(100,100);
	}
 
  
}


//Passar a classe motores
void stop(void){
//Stop
  digitalWrite(E1,LOW);  
  digitalWrite(E2,LOW);     
}  

//Passar a classe motores
void virar_D(int a,int b) {
  analogWrite (E1,a);      
  digitalWrite(M1,HIGH);   
  analogWrite (E2,b);   
  digitalWrite(M2,HIGH);

}

//Passar a classe motores
void andar_F (int a,int b){
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);   
  analogWrite (E2,b);   
  digitalWrite(M2,LOW);
  
}

//Passar a classe motores
void virar_E(int a,int b) {
  analogWrite (E1,a);
  digitalWrite(M1,LOW);  
  analogWrite (E2,b);   
  digitalWrite(M2,LOW);
  
}


//passar a classe ultrasom
int medir_dist(){
  int dur, dist;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  dur = pulseIn(echoPin, HIGH);
  dist = (dur/2) / 29.1;
  return dist;
}


void loop() 
{
  //MFV++ Iteração contínua
  DecideBestDirection();
  delay(LoopCicleDelay);
}
