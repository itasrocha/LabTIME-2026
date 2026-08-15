#pragma once
#include <vector>
#include <memory>
#include "EnergyCoreObserver.hpp"

/**
 * @class EnergyCore
 * @brief Representa o núcleo principal de energia da nave.
 * 
 * O EnergyCore é o Subject no padrão Observer. Ele mantém um nível de energia
 * e notifica todos os observadores anexados (como escudos, luzes e painéis) quando
 * o seu nível de energia se torna crítico.
 */
class EnergyCore {
private:
    int energyLevel; ///< O nível atual de energia do núcleo.
    std::vector<std::weak_ptr<EnergyCoreObserver>> observers; ///< Lista de observadores registrados.
public:
    /**
     * @brief Constrói um EnergyCore com um nível de energia padrão (100).
     */
    EnergyCore();

    /**
     * @brief Anexa um observador ao núcleo de energia.
     * @param observer Ponteiro para o observador a ser anexado.
     */
    void attachObserver(std::shared_ptr<EnergyCoreObserver> observer);

    /**
     * @brief Desanexa um observador do núcleo de energia.
     * @param observer Ponteiro para o observador a ser desanexado.
     */
    void detachObserver(std::shared_ptr<EnergyCoreObserver> observer);

    /**
     * @brief Notifica todos os observadores anexados sobre um estado crítico de energia.
     */
    void notifyObservers();

    /**
     * @brief Obtém o nível atual de energia.
     * @return O nível atual de energia.
     */
    int getEnergy() const;

    /**
     * @brief Drena energia do núcleo. Se a energia cair para o nível crítico (30), notifica os observadores.
     * @param amount A quantidade de energia a ser drenada.
     */
    void drainEnergy(unsigned int amount);
};
