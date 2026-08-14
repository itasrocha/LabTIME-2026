#pragma once

/**
 * @class EnergyCoreObserver
 * @brief Interface para os observadores do EnergyCore.
 * 
 * Declara o método update que os observadores concretos devem implementar
 * para reagir a mudanças no estado do EnergyCore.
 */
class EnergyCoreObserver{
public:
    /**
     * @brief Chamado pelo EnergyCore observado quando ocorre um evento crítico.
     */
    virtual void update() = 0;

    /**
     * @brief Destrutor virtual.
     */
    virtual ~EnergyCoreObserver() = default;
};