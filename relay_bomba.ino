//#include <Messenger.h>

const int rele_porta1 = 7;
const int rele_porta2 = 6;
int dado;
int x = 0;
  
void setup() 
{ 
 
Serial.begin(9600);
pinMode(rele_porta1,OUTPUT);
pinMode(rele_porta2,OUTPUT);  
} 
  
void loop() {
  digitalWrite(rele_porta1,HIGH);
  digitalWrite(rele_porta2,HIGH);
  
  if (Serial.available() > 0) {
    // verifica se tem algum dado na serial
     //lê o primeiro dado do buffer da serial
    
    dado = Serial.read(); 
    // x = Serial.read(); 
    if (dado == 'A') {     //se for A
      digitalWrite(rele_porta1, HIGH); //aciona o pino
      digitalWrite(rele_porta2, HIGH);
    } 

    if (dado == 'D') {     //se for D
      digitalWrite(rele_porta1, LOW);  //desativa o pino
    }
    if (dado == 'B'){
     
       
      digitalWrite(rele_porta1,LOW);
      delay(1000);
      digitalWrite(rele_porta1,HIGH);
      delay(1000);
      digitalWrite(rele_porta2,LOW);
      delay(1000);
      digitalWrite(rele_porta2,HIGH);
      delay(1000);
      Serial.println(x);
     }
  }
}
