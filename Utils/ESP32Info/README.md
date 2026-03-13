# ESP32Info

Biblioteca para exibir informações detalhadas do ESP32-S3.

## Descrição

Esta biblioteca fornece uma interface simples para obter e exibir informações sobre o hardware ESP32-S3, incluindo:

- **Chip**: Modelo, revisão, número de núcleos, frequência
- **Flash**: Tamanho e velocidade
- **PSRAM**: Tamanho total e memória livre
- **Heap**: Tamanho total e memória livre
- **Rede**: Endereço MAC
- **GPIO**: Mapeamento de pinos disponíveis e suas funções

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

### `printGPIOMap(bool showState = true)`

Exibe o mapeamento real de pinos GPIO do ESP32-S3 com detecção de estado.

- **showState**: Se `true` (padrão), exibe o estado atual (HIGH/LOW) de cada pino

```cpp
// Mapeamento com estado dos pinos
esp32Info.printGPIOMap();

// Mapeamento sem estado (apenas lista de pinos válidos)
esp32Info.printGPIOMap(false);
```

**O método detecta automaticamente:**

- Pinos GPIO válidos (0-21, 33-48)
- Pinos reservados (22-32: Flash/PSRAM)
- Estado atual de cada pino (HIGH/LOW)
- Pinos especiais (USB, Serial, LED RGB, etc)

## Dependências

- Arduino.h
- WiFi.h (ESP32)

## Compatibilidade

- ESP32-S3
- ESP32 (outras variantes devem funcionar, mas foram testadas apenas no S3)
