

const int rele_porta1 = 7;
int dado;
  
void setup() 
{ 
 
Serial.begin(9600);
pinMode(rele_porta1,OUTPUT);
digitalWrite(rele_porta1,LOW);  
} 
  
void loop() {
  if (Serial.available() > 0) {
    // verifica se tem algum dado na serial
    dado = Serial.read();  //lê o primeiro dado do buffer da serial

    if (dado == 'A') {     //se for A
      digitalWrite(rele_porta1, HIGH); //aciona o pino
    } 

    if (dado == 'D') {     //se for D
      digitalWrite(rele_porta1, LOW);  //desativa o pino
    }
    if (dado == 'B'){
      digitalWrite(rele_porta1,HIGH);
      delay(1000);
      digitalWrite(rele_porta1,LOW);
      delay(1000);
     }
  }
}
