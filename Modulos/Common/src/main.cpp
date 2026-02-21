#include <Arduino.h>
#include <ESP32Info.h>

ESP32Info esp32Info;

void setup() {
  // Inicializa Serial via USB CDC
  Serial.begin(115200);
  delay(1000);

  // Exibe todas as informações do ESP32
  esp32Info.printAll();
}

void loop() {
  // Mostra uso de memória periodicamente
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 5000) {
    lastPrint = millis();
    esp32Info.printMemoryUsage(millis());
  }

  delay(100);
}
