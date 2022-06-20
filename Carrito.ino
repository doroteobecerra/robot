//Sensor
 int TRIG = 7;
 int ECO = 6;
 int DURACION;
 float DISTANCIA;

//Ruedas
 int IN1 = 2; //verde
 int IN2 = 3; //azul
 int EN1 = 5; //amarillo

 int IN3 = 8; //morado
 int IN4 = 9; //gris
 int EN2 = 11; //blanco
 int VELOCIDAD;

 //Distancias
 int maxDist = 20;
 int minDist = 2;
 

void setup() {
  //sensor
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  Serial.begin(9600);

  //ruedas
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN1, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN2, OUTPUT);
}

void loop() {
     DISTANCIA = calcularDistancia(); 
     if (DISTANCIA <= maxDist && DISTANCIA >= minDist){ 
        detener();   
        delay (200);
        izquierda();
        delay(600);
     }
     else{                        
        avanzar(); 
     }
}

void avanzar(){
    digitalWrite(EN1, HIGH);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(EN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void detener(){
    digitalWrite(EN1, LOW);
    digitalWrite(EN2, LOW);
}

void derecha(){
    digitalWrite(EN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void izquierda(){
    digitalWrite(EN1, HIGH);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(EN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

float calcularDistancia(){
   digitalWrite(TRIG, HIGH);
   delay(1);
   digitalWrite(TRIG, LOW);
   DURACION = pulseIn(ECO, HIGH);
   DISTANCIA = DURACION / 58.2;
   return DISTANCIA;
}
