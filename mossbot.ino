// MFV++ 
// MOSSBot
// 


//Parâmetros do MOSSBot
const int SafeDistance = 15; //centímetros
const int LoopCicleDelay = 20; //milisegundos

bool turningLeft = false;
bool turningRight = false;


//MFV++ Configurações do MOSSBot
void setup() 
{ 
  Serial.begin(9600);
  //TODO: declarar portas de motores e ultrasom, aqui ou nas classes próprias
  //Declarar Portas dos Motores
  //pinMode(2, OUTPUT);
  //pinMode(3, INPUT);
  //pinMode(4, OUTPUT);pinMode(5, OUTPUT);     
  //pinMode(6, OUTPUT);pinMode(7, OUTPUT);  	
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


//MFV++ Deverá passar a classe própria
//TODO: criar classe própria e implementar função
//pode ser aproveitado o código do ultrasom.ino
int SonnarGetDistance()
{

}


void loop() 
{
  //MFV++ Iteração contínua
  DecideBestDirection();
  delay(LoopCicleDelay);
}
