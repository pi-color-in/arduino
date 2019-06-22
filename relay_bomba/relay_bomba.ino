

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
    if (serialInput == ',') {
      Serial.print("Value:");
      Serial.println(data.toInt());
      Serial.print("String:");
      data.remove(data.length()-1);
      Serial.println(data);
      data = "";
    }
  }
}
