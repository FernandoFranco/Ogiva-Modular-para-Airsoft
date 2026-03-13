#ifndef I2CSCANNER_H
#define I2CSCANNER_H

#include <Arduino.h>
#include <Wire.h>

/**
 * @brief Classe para escanear dispositivos I2C no barramento
 *
 * Permite identificar todos os dispositivos I2C conectados,
 * exibindo seus endereços e informações úteis para debug.
 */
class I2CScanner {
 public:
  /**
   * @brief Construtor padrão (usa pinos padrão do ESP32)
   */
  I2CScanner();

  /**
   * @brief Construtor com pinos customizados
   * @param sda_pin Pino SDA
   * @param scl_pin Pino SCL
   */
  I2CScanner(int sda_pin, int scl_pin);

  /**
   * @brief Inicializa o barramento I2C
   * @param frequency Frequência do barramento em Hz (padrão: 100000)
   * @return true se inicializado com sucesso
   */
  bool begin(uint32_t frequency = 100000);

  /**
   * @brief Escaneia o barramento I2C e exibe os dispositivos encontrados
   * @return Número de dispositivos encontrados
   */
  int scan();

  /**
   * @brief Escaneia silenciosamente (sem imprimir no Serial)
   * @param addresses Array para armazenar os endereços encontrados
   * @param maxDevices Tamanho máximo do array
   * @return Número de dispositivos encontrados
   */
  int scanSilent(uint8_t* addresses, uint8_t maxDevices);

  /**
   * @brief Verifica se um endereço específico está presente
   * @param address Endereço a verificar (0x00 a 0x7F)
   * @return true se o dispositivo responde
   */
  bool isDevicePresent(uint8_t address);

  /**
   * @brief Obtém o nome do dispositivo comum para um endereço
   * @param address Endereço do dispositivo
   * @return Nome do dispositivo comum ou "Desconhecido"
   */
  const char* getDeviceName(uint8_t address);

 private:
  int _sda_pin;
  int _scl_pin;
  bool _initialized;

  // Tabela de dispositivos I2C comuns
  struct DeviceInfo {
    uint8_t address;
    const char* name;
  };

  static const DeviceInfo _knownDevices[];
};

#endif  // I2CSCANNER_H
