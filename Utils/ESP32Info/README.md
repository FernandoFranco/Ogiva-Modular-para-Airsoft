# ESP32Info

Biblioteca para exibir informações detalhadas do ESP32-S3.

## Descrição

Esta biblioteca fornece uma interface simples para obter e exibir informações sobre o hardware ESP32-S3, incluindo:

- **Chip**: Modelo, revisão, número de núcleos, frequência
- **Flash**: Tamanho e velocidade
- **PSRAM**: Tamanho total e memória livre
- **Heap**: Tamanho total e memória livre
- **Rede**: Endereço MAC

## Uso

```cpp
#include <Arduino.h>
#include <ESP32Info.h>

ESP32Info esp32Info;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Exibe todas as informações
  esp32Info.printAll();
}

void loop() {
  // Exibe uso de memória periodicamente
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 5000) {
    lastPrint = millis();
    esp32Info.printMemoryUsage(millis());
  }
  delay(100);
}
```

## Métodos Disponíveis

### `printAll()`

Exibe todas as informações do ESP32 de forma formatada.

### `printChipInfo()`

Exibe apenas informações do chip (modelo, revisão, núcleos, frequência).

### `printFlashInfo()`

Exibe apenas informações da memória Flash.

### `printPsramInfo()`

Exibe apenas informações da PSRAM.

### `printHeapInfo()`

Exibe apenas informações do Heap (RAM).

### `printNetworkInfo()`

Exibe apenas informações de rede (MAC Address).

### `printMemoryUsage(unsigned long timestamp)`

Exibe o uso atual de memória (Heap e PSRAM) com timestamp.

## Dependências

- Arduino.h
- WiFi.h (ESP32)

## Compatibilidade

- ESP32-S3
- ESP32 (outras variantes devem funcionar, mas foram testadas apenas no S3)
