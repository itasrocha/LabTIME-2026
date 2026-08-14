#pragma once

/**
 * @class Weapon
 * @brief Interface base para todas as armas e modificadores de armas.
 * 
 * Atua como a interface Component no padrão Decorator.
 */
class Weapon {
public:
    /**
     * @brief Destrutor virtual.
     */
    virtual ~Weapon() = default;

    /**
     * @brief Dispara a arma, aplicando os seus efeitos específicos.
     */
    virtual void shoot() const = 0;
};