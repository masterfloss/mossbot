// MFV++ 
// MOSSBot
// 


//TODO: criar classes próprias para motor e ultrasom
//#include <motores.ino>
//#include <ultrasom.ino>


//Parâmetros do MOSSBot
const int SafeDistance = 15; //segundos
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
  int distance = SonnarGetDistance();
  Serial.print("Distância actual = ");
  Serial.print(distance);
  
  //MFV++ distância de segurança 
  if(distance < SafeDistance)
  {
	//valida se já está a virar para algum lado
	if (turningLeft)
		//TODO: invocar motor vira à esquerda
		//continua a virar à esquerda
	else if (turningRight)
		//TODO: invocar motor vira à direita
		//continua a virar à direita
	else
	{
		//TODO: invocar motor pára
		//parar motor
		 
		//se tiver servo no futuro, poderemos validar se temos obstáculo à esquerda ou à direita e escolher
		//para já vira para um lado qualquer
		 
		if(random(100) > 50)
		{
			//vira à direita
			turningRight = true;
		    	turningLeft = false;
		    	//Implementar classe motor
		    	//TODO: invocar motor vira à direita
			//motor.turnRight(50);
		    	//digtialWrite(dir, HIGH);
			Serial.println("Turning Right");
		}
		else
		{
		    //vira à esquerda
		    turningLeft = true;
		    turningRight = false;
		    //Implementar classe motor
		    //TODO: invocar motor vira à esquerda
		    //motor.turnLeft(50);
		    //digtialWrite(dir, LOW);
	            Serial.println("Turning Left");
		  }
		}
	}
	else
	{
		turningLeft = false;
		turningRight = false;
		//implementar
		//motor.moveForward(50);
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
