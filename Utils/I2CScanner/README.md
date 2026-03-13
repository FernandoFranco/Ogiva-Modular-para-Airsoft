# I2CScanner

Biblioteca para escanear e identificar dispositivos I2C conectados ao barramento.

## Descrição

Esta biblioteca facilita a identificação de dispositivos I2C, permitindo:

- **Escanear** todos os endereços I2C (0x01 a 0x7E)
- **Identificar** dispositivos comuns automaticamente
- **Verificar** se um endereço específico está presente
- **Configurar** pinos SDA/SCL customizados

## Uso

### Exemplo básico

```cpp
#include <Arduino.h>
#include <I2CScanner.h>

I2CScanner scanner;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Inicializa I2C com pinos padrão
  scanner.begin();

  // Escaneia e mostra dispositivos
  scanner.scan();
}

void loop() {
  delay(5000);

  // Escaneia periodicamente
  int devices = scanner.scan();
  Serial.printf("Dispositivos encontrados: %d\n", devices);
}
```

### Exemplo com pinos customizados

```cpp
// Define pinos customizados (SDA, SCL)
I2CScanner scanner(21, 22);

void setup() {
  Serial.begin(115200);

  // Inicializa com frequência customizada (400kHz)
  scanner.begin(400000);

  scanner.scan();
}
```

### Verificar dispositivo específico

```cpp
void loop() {
  // Verifica se existe um display OLED em 0x3C
  if (scanner.isDevicePresent(0x3C)) {
    Serial.println("Display OLED encontrado!");
  }

  delay(5000);
}
```

### Escanear silenciosamente

```cpp
void loop() {
  uint8_t addresses[10];
  int count = scanner.scanSilent(addresses, 10);

  Serial.printf("Encontrados %d dispositivos:\n", count);
  for (int i = 0; i < count; i++) {
    Serial.printf("  - 0x%02X\n", addresses[i]);
  }

  delay(5000);
}
```

## Métodos Disponíveis

### `begin(uint32_t frequency = 100000)`

Inicializa o barramento I2C.

- **frequency**: Frequência do barramento em Hz (padrão: 100kHz)
- **Retorna**: `true` se inicializado com sucesso

### `scan()`

Escaneia o barramento e exibe os dispositivos encontrados no Serial.

- **Retorna**: Número de dispositivos encontrados

### `scanSilent(uint8_t* addresses, uint8_t maxDevices)`

Escaneia sem imprimir no Serial.

- **addresses**: Array para armazenar os endereços
- **maxDevices**: Tamanho máximo do array
- **Retorna**: Número de dispositivos encontrados

### `isDevicePresent(uint8_t address)`

Verifica se um endereço específico responde.

- **address**: Endereço a verificar (0x00 a 0x7F)
- **Retorna**: `true` se o dispositivo responde

### `getDeviceName(uint8_t address)`

Obtém o nome de dispositivos comuns.

- **address**: Endereço do dispositivo
- **Retorna**: Nome do dispositivo ou `nullptr` se desconhecido

## Dispositivos Reconhecidos

A biblioteca identifica automaticamente dispositivos comuns:

- **0x20, 0x38**: PCF8574 I/O Expander
- **0x27**: LCD I2C
- **0x3C, 0x3D**: OLED Display (SSD1306)
- **0x48-0x4B**: ADS1115 ADC
- **0x50-0x57**: AT24C EEPROM
- **0x53**: ADXL345 Accelerometer
- **0x68**: DS1307/DS3231 RTC ou MPU6050
- **0x69**: MPU6050 IMU
- **0x76, 0x77**: BMP280/BME280 Sensor

## Dependências

- Arduino.h
- Wire.h (ESP32)

## Compatibilidade

- ESP32-S3
- ESP32 (todas as variantes)
- Qualquer placa compatível com Wire.h

## Pinos Padrão ESP32-S3

- **SDA**: GPIO 21
- **SCL**: GPIO 22

Para usar outros pinos, utilize o construtor customizado.
