

String data = "";    // string to hold input

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
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
      // formato do dado a ser recebido 2000,1500,1000,0500,0250
      String SCyan = getValue(data, ',', 0);
      String SMagenta = getValue(data, ',', 1);
      String SYellow = getValue(data, ',', 2);
      String SBlack = getValue(data, ',', 3);
      String SBase = getValue(data, ',', 4);

      Serial.println("cyan:" + SCyan);
      Serial.println("magenta:" + SMagenta);
      Serial.println("yellow:" + SYellow);
      Serial.println("black:" + SBlack);
      Serial.println("base:" + SBase);

      // int cyan = (int)SCyan.toInt();
      // int magenta = SMagenta.toInt();
      // int yellow = SYellow.toInt();
      // int black = SBlack.toInt();
      // int base = SBase.toInt();
      //
      // Serial.println("cyan:" + cyan);
      // Serial.println("magenta:" + magenta);
      // Serial.println("yellow:" + yellow);
      // Serial.println("black:" + black);
      // Serial.print("base:" + base);
      // clear the string for new input:
      data = "";
    }
  }
}
