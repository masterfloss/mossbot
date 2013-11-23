
#define trigPin 2
#define echoPin 3

// Iniciar
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

int medir_dist(){
  int dur, dist;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  dur = pulseIn(echoPin, HIGH);
  dist = (dur/2) / 29.1;
  return dist;
}

// ciclo principal
void loop() {
  int distancia;
  distancia = medir_dist();
  if (distancia >= 200 || distancia <= 0){
    Serial.println("Fora de alcance");
  }
  else {
    Serial.print(distancia);
    Serial.println(" cm");
  }
  delay(500);
}
