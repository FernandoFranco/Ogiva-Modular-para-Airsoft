#include <Arduino.h>
#include <ESP32Info.h>

// Definições
const int LED_PIN = 15;

ESP32Info esp32Info;

void setup() {
  // Inicializa Serial via USB CDC
  Serial.begin(115200);
  delay(1000);

  // Configura LED
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // Exibe todas as informações do ESP32
  esp32Info.printAll();
}

void loop() {
  // Pisca LED a cada 500ms
  static unsigned long lastBlink = 0;
  if (millis() - lastBlink > 500) {
    lastBlink = millis();
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }

  // Mostra uso de memória periodicamente
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 5000) {
    lastPrint = millis();
    esp32Info.printMemoryUsage(millis());
  }

  delay(100);
}
