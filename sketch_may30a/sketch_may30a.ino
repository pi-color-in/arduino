//#include <Messenger.h>


const int rele_porta1 = 7;
const int rele_porta2 = 6;
const int rele_porta3 = 5;
int dado;
int x = 0;
  
void setup() 
{ 
 
Serial.begin(9600);
pinMode(rele_porta1,OUTPUT);
pinMode(rele_porta2,OUTPUT);  
pinMode(rele_porta3,OUTPUT);  
} 
  
void loop() {
  digitalWrite(rele_porta1,HIGH);
  digitalWrite(rele_porta2,HIGH);
  digitalWrite(rele_porta3,HIGH);
  
  if (Serial.available() > 0) {
    // verifica se tem algum dado na serial
     //lê o primeiro dado do buffer da serial
    
    dado = Serial.read(); 
    // x = Serial.read(); 
    
    if (dado == 'B'){   
      digitalWrite(rele_porta1,LOW); //liga
      delay(1000);
      digitalWrite(rele_porta1,HIGH); //desliga
      delay(1000);
      digitalWrite(rele_porta2,LOW); //liga
      delay(1000);
      digitalWrite(rele_porta2,HIGH); //desliga
      delay(1000);
      digitalWrite(rele_porta3,LOW); //liga
      delay(1000);
      digitalWrite(rele_porta3,HIGH); //desliga
      delay(1000);
      Serial.println(x);
     }
  }
}
