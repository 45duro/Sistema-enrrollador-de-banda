int motAdel = 5, motAtras = 6, velocidad = 127, tiempoEnrrollado = 5000;
int sensorInicio = 2, sensorFinal = 3, pinPulsador = 7;
char dato = 0;
int lecInicio = 0, lecFinal = 0, lecPul = 0; 
void setup() {

  Serial.begin(9600);
  pinMode(motAdel,1);
  pinMode(motAtras,1);
 
}

void loop() {

  //Lectura de sensores
  lecInicio = digitalRead(sensorInicio);
  lecFinal = digitalRead(sensorFinal);
  lecPul = digitalRead(pinPulsador);


 if (Serial.available()>0){
  dato = Serial.read();
  Serial.println(dato);
 }
 

 

 switch (dato){
  case 'a':
    //Serial.println("Entro"); 
    adelante(velocidad);
    break;

  case 'b': 
    atras();
    break;

  case 'f': 
    buscarPosicion();
    break;

  case 'p':
    arrancarSistema();
    break;
  
  default:
    parar();
    break;
 }
 

}


void buscarPosicion(){
  do{
    lecInicio = digitalRead(sensorInicio);
    atras();
    
  }while(lecInicio == 1);
  parar();
  dato = 0;
}

void adelante(byte v){
  analogWrite(motAdel,v);
}

void atras(){
  analogWrite(motAtras,velocidad);
}

void parar(){
  analogWrite(motAtras, 0);
  analogWrite(motAdel, 0);
}

void arrancarSistema(){
  do{
    lecFinal = digitalRead(sensorFinal);
    adelante(200);
    
  }while(lecFinal == 1);
  adelante(110);
  delay(tiempoEnrrollado);
  parar();
  dato = 'f';
}
