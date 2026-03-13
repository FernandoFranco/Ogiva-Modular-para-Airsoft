#include "ESP32Info.h"
#include "driver/gpio.h"
#include "soc/gpio_sig_map.h"

ESP32Info::ESP32Info() {
  // Construtor vazio - não há inicialização necessária
}

void ESP32Info::printAll() {
  Serial.println("\n\n=== ESP32-S3-DevKitC-1 N16R8 ===");
  Serial.println("Informações do Hardware:");
  Serial.println();

  printChipInfo();
  printFlashInfo();
  printPsramInfo();
  printHeapInfo();
  printNetworkInfo();
  printGPIOMap();

  Serial.println("\n✓ Sistema inicializado com sucesso!");
  Serial.println("====================================\n");
}

void ESP32Info::printChipInfo() {
  Serial.println("--- Chip ---");
  Serial.printf("Modelo: %s\n", ESP.getChipModel());
  Serial.printf("Revisão: %d\n", ESP.getChipRevision());
  Serial.printf("Núcleos: %d\n", ESP.getChipCores());
  Serial.printf("Frequência: %d MHz\n", ESP.getCpuFreqMHz());
  Serial.println();
}

void ESP32Info::printFlashInfo() {
  Serial.println("--- Memória Flash ---");
  Serial.printf("Tamanho: %d MB\n", ESP.getFlashChipSize() / (1024 * 1024));
  Serial.printf("Velocidade: %d MHz\n", ESP.getFlashChipSpeed() / 1000000);
  Serial.println();
}

void ESP32Info::printPsramInfo() {
  Serial.println("--- PSRAM ---");
  Serial.printf("Tamanho: %d MB\n", ESP.getPsramSize() / (1024 * 1024));
  Serial.printf("Livre: %d KB\n", ESP.getFreePsram() / 1024);
  Serial.println();
}

void ESP32Info::printHeapInfo() {
  Serial.println("--- Heap (RAM) ---");
  Serial.printf("Tamanho: %d KB\n", ESP.getHeapSize() / 1024);
  Serial.printf("Livre: %d KB\n", ESP.getFreeHeap() / 1024);
  Serial.println();
}

void ESP32Info::printNetworkInfo() {
  Serial.println("--- Rede ---");
  Serial.printf("MAC Address: %s\n", WiFi.macAddress().c_str());
}

void ESP32Info::printMemoryUsage(unsigned long timestamp) {
  Serial.printf("[%lu s] Free Heap: %d KB | Free PSRAM: %d KB\n", timestamp / 1000,
                ESP.getFreeHeap() / 1024, ESP.getFreePsram() / 1024);
}

void ESP32Info::printGPIOMap(bool showState) {
  Serial.println("--- Mapeamento GPIO ESP32-S3 ---");
  Serial.println();

  if (showState) {
    Serial.println("GPIO | ESTADO | VALIDO | OBSERVAÇÕES");
    Serial.println("-----+--------+--------+-----------------------------------");
  } else {
    Serial.println("GPIO | VALIDO | OBSERVAÇÕES");
    Serial.println("-----+--------+-----------------------------------");
  }

  // Varre todos os GPIOs possíveis do ESP32-S3 (0-48)
  for (uint8_t pin = 0; pin <= 48; pin++) {
    if (isReservedPin(pin)) {
      // Pula a faixa reservada
      if (pin == 22) {
        Serial.println("22-32|   -    |   NÃO  | ⚠️ RESERVADOS (Flash/PSRAM)");
        pin = 32;  // Pula para 33
      }
      continue;
    }

    bool valid = isValidGPIO(pin);
    String state = showState ? getGPIOState(pin) : "";
    String obs = "";

    // Adiciona observações especiais
    if (pin == 0)
      obs = "⚠️ Boot/Strapping";
    else if (pin == 3)
      obs = "JTAG: MTDO";
    else if (pin == 19 || pin == 20)
      obs = "⚠️ USB OTG";
    else if (pin == 43)
      obs = "⚠️ Serial TX";
    else if (pin == 44)
      obs = "⚠️ Serial RX";
    else if (pin == 45)
      obs = "⚠️ VDD_SPI";
    else if (pin == 46)
      obs = "Strapping";
    else if (pin == 48)
      obs = "✨ LED RGB";

    if (showState) {
      Serial.printf("%2d   | %-6s | %-6s | %s\n", pin, valid ? state.c_str() : "  -",
                    valid ? "SIM" : "NÃO", obs.c_str());
    } else {
      Serial.printf("%2d   | %-6s | %s\n", pin, valid ? "SIM" : "NÃO", obs.c_str());
    }
  }

  Serial.println();
  Serial.printf("Total de GPIOs válidos: %d\n", 49 - 11);  // 49 pinos - 11 reservados (22-32)
  Serial.println();
}

bool ESP32Info::isValidGPIO(uint8_t pin) {
  // GPIOs não existentes ou reservados no ESP32-S3
  if (pin >= 22 && pin <= 32) return false;  // Flash/PSRAM
  if (pin > 48) return false;                // Não existe
  return true;
}

String ESP32Info::getGPIOState(uint8_t pin) {
  if (!isValidGPIO(pin)) {
    return "INVAL";
  }

  // Tenta ler o estado do pino
  int level = digitalRead(pin);
  return level == HIGH ? "HIGH" : "LOW";
}

bool ESP32Info::isReservedPin(uint8_t pin) { return (pin >= 22 && pin <= 32); }
