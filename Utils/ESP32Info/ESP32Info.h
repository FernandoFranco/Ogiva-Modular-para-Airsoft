#ifndef ESP32INFO_H
#define ESP32INFO_H

#include <Arduino.h>
#include <WiFi.h>

/**
 * @brief Classe para exibir informações do ESP32-S3
 *
 * Fornece métodos para exibir informações sobre:
 * - Hardware (modelo, revisão, núcleos, frequência)
 * - Memória Flash
 * - PSRAM
 * - RAM (Heap)
 * - Rede (MAC Address)
 */
class ESP32Info {
 public:
  /**
   * @brief Construtor padrão
   */
  ESP32Info();

  /**
   * @brief Exibe todas as informações do ESP32 no Serial
   */
  void printAll();

  /**
   * @brief Exibe informações do chip (modelo, revisão, núcleos, frequência)
   */
  void printChipInfo();

  /**
   * @brief Exibe informações da memória Flash
   */
  void printFlashInfo();

  /**
   * @brief Exibe informações da PSRAM
   */
  void printPsramInfo();

  /**
   * @brief Exibe informações da memória RAM (Heap)
   */
  void printHeapInfo();

  /**
   * @brief Exibe informações de rede (MAC Address)
   */
  void printNetworkInfo();

  /**
   * @brief Exibe uso atual de memória (Heap e PSRAM)
   * @param timestamp Timestamp em milissegundos para exibir
   */
  void printMemoryUsage(unsigned long timestamp);

  /**
   * @brief Exibe mapeamento completo dos pinos GPIO com estado real
   * @param showState Se true, exibe o estado atual de cada pino
   */
  void printGPIOMap(bool showState = true);

 private:
  // Verifica se um pino GPIO é válido no ESP32-S3
  static bool isValidGPIO(uint8_t pin);

  // Obtém o estado de um pino (HIGH/LOW ou modo)
  static String getGPIOState(uint8_t pin);

  // Verifica se o pino é reservado (Flash/PSRAM)
  static bool isReservedPin(uint8_t pin);
};

#endif  // ESP32INFO_H
