

String data = "";    // string to hold input
const int relayPort1 = 7;
const int relayPort2 = 6;
const int relayPort3 = 5;
const int relayPort4 = 4;
const int relayPort5 = 3;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  pinMode(relayPort1,OUTPUT);
  pinMode(relayPort2,OUTPUT);
  pinMode(relayPort3,OUTPUT);
  pinMode(relayPort4,OUTPUT);
  pinMode(relayPort5,OUTPUT);
  while (!Serial) {
    Serial.println("(!Serial)");
    // wait for serial port to connect. Needed for native USB port only
  }
}

String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void loop() {
  digitalWrite(relayPort1,HIGH);
  digitalWrite(relayPort2,HIGH);
  digitalWrite(relayPort3,HIGH);
  digitalWrite(relayPort4,HIGH);
  digitalWrite(relayPort5,LOW);

  // le o input do serial
  while (Serial.available() > 0) {
    int serialInput = Serial.read();
    if (serialInput) {
      // converte a entrada para char e adiciona em uma string
      data += (char)serialInput;
    }
    // quando receber um enter executa
    if (serialInput == '\n') {
      Serial.print("Value:");
      Serial.println(data.toInt());
      Serial.print("String:");
      Serial.println(data);

      // separa a string recebida a cada virgula e joga os
      // dados nas variaveis corretas, C-yan M-agenta Y-ellow blac-K B-ase
      // formato do dado a ser recebido :
      // 2000,1500,1000,0500,0250

      // C-yan = 0 - primeiro elemento
      String SCyan = getValue(data, ',', 0);
      // M-agenta = 1 - segundo elemento
      String SMagenta = getValue(data, ',', 1);
      // Y-ellow = 2 - terceiro elemento
      String SYellow = getValue(data, ',', 2);
      // blac-K = 3 - quarto elemento
      String SBlack = getValue(data, ',', 3);
      // B-ase = 4 - quinto elemento
      String SBase = getValue(data, ',', 4);

      Serial.println("cyan:" + SCyan);
      digitalWrite(relayPort1,LOW); //liga
      delay(SCyan.toInt());
      digitalWrite(relayPort1,HIGH); //desliga

      Serial.println("magenta:" + SMagenta);
      digitalWrite(relayPort2,LOW); //liga
      delay(SMagenta.toInt());
      digitalWrite(relayPort2,HIGH); //desliga

      Serial.println("yellow:" + SYellow);
      digitalWrite(relayPort3,LOW); //liga
      delay(SYellow.toInt());
      digitalWrite(relayPort3,HIGH); //desliga

      Serial.println("black:" + SBlack);
      digitalWrite(relayPort4,LOW); //liga
      delay(SBlack.toInt());
      digitalWrite(relayPort4,HIGH); //desliga

      Serial.println("base:" + SBase);
      digitalWrite(relayPort5,HIGH); //liga
      delay(SBase.toInt());
      digitalWrite(relayPort5,LOW); //desliga
      data = "";
    }
  }
}
