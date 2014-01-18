// iniciar
// abrir porto série com taxa de transmissão de 9600 bps
void setup(){
  Serial.begin(9600); 
}

// ligar sensor de escala de cinzentos a pino anaógico 5
// imprimir o valor através do porto série

void loop(){
      int valor;
      valor=analogRead(5);   
      Serial.println(valor,DEC);       
      delay(100);
}
