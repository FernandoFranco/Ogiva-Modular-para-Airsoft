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

private:
    // Nenhum dado membro necessário no momento
};

#endif // ESP32INFO_H
