#include "ESP32Info.h"

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
    Serial.printf("[%lu s] Free Heap: %d KB | Free PSRAM: %d KB\n", 
                  timestamp / 1000, 
                  ESP.getFreeHeap() / 1024,
                  ESP.getFreePsram() / 1024);
}
