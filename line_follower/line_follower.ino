// MFV++ 
// MOSSBot
// 
// A nxt4you and MOSS project
// Versão inicial que segue linhas
// 

//Parâmetros do MOSSBot ==========================================

const int turnSpeed = 100; //velocidade a curvar
const int fullSpeed = 255; //velocidade máxima

bool turningLeft = false;
bool turningRight = false;

//Pins  ==========================================================
//Standard PWM DC control
const int E1 = 5;    //Controlo de velocidade de M1 
const int E2 = 6;    //Controlo de velocidade de M2 
const int M1 = 4;    //Controlo de direcção de M1 
const int M2 = 7;    //Controlo de direcção de  M2 
//ultrasom
#define trigPin 2   
#define echoPin 3
//cor
#define lLinePin 5
#define rLinePin 4 //TODO: MFV++ validar se é possível utilizar este pin

// Setup =========================================================

//MFV++ Configurações do MOSSBot
void setup() 
{ 

  //ultrasom
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  //Declarar Portas dos Motores
  //pinMode(2, OUTPUT);
  //pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);     
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);  	
  
  // abrir porto série com taxa de transmissão de 9600 bps
  Serial.begin(9600);  
} 

// Loop ==========================================================
void loop() 
{
  //MFV++ Iteração contínua
  DecideBestDirection();
  FollowLine();
  delay(LoopCicleDelay);
}

// Follow LineBehaviour ==================================

//MFV++ Deverá passar a classe própria
int FollowLine()
{
	int black = 100;//TODO: MFV++ alterar para valor que seja o menor preto a seguir
	int left;
	int right;
    left=analogRead(5);
	right=analogRead(4);   
	
	//Se ambos os sensores derem branco, estamos perdidos
	//rotina a contemplar posteriormente
	if (left < black)
	{
		virar_E(turnSpeed,turnSpeed);
	}
	if (right < black)
	{
		virar_D(turnSpeed,turnSpeed);
	}
	
}

// Obstacle Avoidance Behaviour ==================================

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
    {
      virar_E(turnSpeed,turnSpeed);
    }
    else if (turningRight)
    {
      //continua a virar à direita
       virar_D(turnSpeed,turnSpeed);
    }
    else
    {
      //parar motor
      stop();

      //se tiver servo no futuro, poderemos validar se temos obstáculo à esquerda ou à direita e escolher
      //para já vira para um lado qualquer	 
      if(random(100) > 50)
      {
        //vira à direita
	turningRight = true;
	turningLeft = false;
	virar_D(turnSpeed,turnSpeed);
	Serial.println("Vira à direita");
      }
      else
      {
        //vira à esquerda
        turningLeft = true;
	turningRight = false;
	virar_E(turnSpeed,turnSpeed);
	Serial.println("Vira à esquerda");
      }
    }
  }
  else
  {
    turningLeft = false;
    turningRight = false;
    andar_F(fullSpeed,fullSpeed);
    Serial.println("Em frente");
  }
}

//Passar a classe motores
void stop(){
  //Stop
  digitalWrite(E1,LOW);
  digitalWrite(E2,LOW);     
}  

//Passar a classe motores
void virar_D(int a,int b) //Virar à direita
{
  analogWrite (E1,a);      
  digitalWrite(M1,HIGH);   
  analogWrite (E2,b);   
  digitalWrite(M2,HIGH);

}

//Passar a classe motores
void andar_F (int a,int b) //Andar para a frente
{
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);   
  analogWrite (E2,b);   
  digitalWrite(M2,LOW);
  
}

//Passar a classe motores
void virar_E(int a,int b) //Virar à esquerda
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);  
  analogWrite (E2,b);   
  digitalWrite(M2,LOW);
  
}

//Passar a classe motores
void andar_T (char a,char b) //Andar para trás
{
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
