#include "I2CScanner.h"

// Dispositivos I2C conhecidos
const I2CScanner::DeviceInfo I2CScanner::_knownDevices[] = {
    {0x20, "PCF8574 I/O Expander"},
    {0x27, "LCD I2C"},
    {0x38, "PCF8574A I/O Expander"},
    {0x3C, "OLED Display (SSD1306)"},
    {0x3D, "OLED Display (SSD1306)"},
    {0x48, "ADS1115 ADC"},
    {0x49, "ADS1115 ADC"},
    {0x4A, "ADS1115 ADC"},
    {0x4B, "ADS1115 ADC"},
    {0x50, "AT24C EEPROM"},
    {0x51, "AT24C EEPROM"},
    {0x52, "AT24C EEPROM"},
    {0x53, "ADXL345 Accelerometer"},
    {0x57, "AT24C EEPROM"},
    {0x68, "DS1307/DS3231 RTC / MPU6050"},
    {0x69, "MPU6050 IMU"},
    {0x76, "BMP280/BME280 Sensor"},
    {0x77, "BMP280/BME280 Sensor"},
    {0x00, nullptr}  // Fim da tabela
};

I2CScanner::I2CScanner() : _sda_pin(SDA), _scl_pin(SCL), _initialized(false) {}

I2CScanner::I2CScanner(int sda_pin, int scl_pin)
    : _sda_pin(sda_pin), _scl_pin(scl_pin), _initialized(false) {}

bool I2CScanner::begin(uint32_t frequency) {
  if (!Wire.begin(_sda_pin, _scl_pin, frequency)) {
    Serial.println("❌ Falha ao inicializar I2C!");
    _initialized = false;
    return false;
  }

  Serial.printf("✓ I2C inicializado (SDA=%d, SCL=%d, Freq=%d Hz)\n", _sda_pin, _scl_pin, frequency);
  _initialized = true;
  return true;
}

int I2CScanner::scan() {
  if (!_initialized) {
    Serial.println("❌ I2C não inicializado! Chame begin() primeiro.");
    return 0;
  }

  Serial.println("\n=== Scanner I2C ===");
  Serial.println("Escaneando barramento I2C...\n");

  int deviceCount = 0;

  for (uint8_t address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    uint8_t error = Wire.endTransmission();

    if (error == 0) {
      // Dispositivo encontrado
      Serial.printf("✓ Dispositivo encontrado em 0x%02X", address);

      const char* deviceName = getDeviceName(address);
      if (deviceName != nullptr) {
        Serial.printf(" - %s", deviceName);
      }

      Serial.println();
      deviceCount++;
    } else if (error == 4) {
      Serial.printf("❌ Erro desconhecido no endereço 0x%02X\n", address);
    }

    delay(10);  // Pequeno delay entre verificações
  }

  Serial.println("\n--- Resultado ---");
  if (deviceCount == 0) {
    Serial.println("Nenhum dispositivo I2C encontrado.");
  } else {
    Serial.printf("Total: %d dispositivo(s) encontrado(s).\n", deviceCount);
  }
  Serial.println("=================\n");

  return deviceCount;
}

int I2CScanner::scanSilent(uint8_t* addresses, uint8_t maxDevices) {
  if (!_initialized) {
    return 0;
  }

  int deviceCount = 0;

  for (uint8_t address = 1; address < 127 && deviceCount < maxDevices; address++) {
    Wire.beginTransmission(address);
    uint8_t error = Wire.endTransmission();

    if (error == 0) {
      addresses[deviceCount++] = address;
    }

    delay(10);
  }

  return deviceCount;
}

bool I2CScanner::isDevicePresent(uint8_t address) {
  if (!_initialized || address > 0x7F) {
    return false;
  }

  Wire.beginTransmission(address);
  uint8_t error = Wire.endTransmission();

  return (error == 0);
}

const char* I2CScanner::getDeviceName(uint8_t address) {
  for (int i = 0; _knownDevices[i].name != nullptr; i++) {
    if (_knownDevices[i].address == address) {
      return _knownDevices[i].name;
    }
  }
  return nullptr;
}
