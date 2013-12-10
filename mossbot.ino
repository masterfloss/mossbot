// MFV++ 
// MOSSBot
// 

bool turningLeft = false;
bool turningRight = false;

//MFV++ Configurações do MOSSBot
void setup() 
{ 
	
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
  
  //MFV++ distância de segurança pode passar a parâmetro
  if(distance < 15)
	{
	  //valida se já está a virar para algum lado
		if (turningLeft)
			//continua a virar à esquerda
		else if (turningRight)
			//continua a virar à direita
		else
		{
		  //parar motor
		  
		  //se tiver servo no futuro, poderemos validar se temos obstáculo à esquerda ou à direita e escolher
		  //para já vira para um lado qualquer
		  
		  if(random(100) > 50)
		  {
		  	//vira à direita
		    turningRight = true;
		    turningLeft = false;
		    //Implementar classe motor
				//motor.turnRight(50);
		    //digtialWrite(dir, HIGH);
				Serial.println("Left");
		  }
		  else
		  {
		    //vira à esquerda
		    turningLeft = true;
		    turningRight = false;
		    //Implementar classe motor
				//motor.turnLeft(50);
		    //digtialWrite(dir, LOW);
				Serial.println("Left");
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
int SonnarGetDistance()
{

}


void loop() 
{
  //MFV++ Iteração contínua
  DecideBestDirection();
  delay(20);
}
