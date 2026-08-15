#pragma once
#include "WeaponDecorator.hpp"

/**
 * @class FireDamageModifier
 * @brief Decorador concreto que adiciona dano de fogo a uma arma.
 */
class FireDamageModifier : public WeaponDecorator {
public:
    /**
     * @brief Constrói o modificador.
     * @param weapon A arma a ser encapsulada.
     */
    explicit FireDamageModifier(std::unique_ptr<Weapon> weapon);

    /**
     * @brief Dispara a arma encapsulada e adiciona efeitos de dano de fogo.
     */
    void shoot() const override;
};

/**
 * @class ArmorPiercingModifier
 * @brief Decorador concreto que adiciona capacidades de perfuração de blindagem.
 */
class ArmorPiercingModifier : public WeaponDecorator {
public:
    /**
     * @brief Constrói o modificador.
     * @param weapon A arma a ser encapsulada.
     */
    explicit ArmorPiercingModifier(std::unique_ptr<Weapon> weapon);

    /**
     * @brief Dispara a arma encapsulada e adiciona efeitos de perfuração de blindagem.
     */
    void shoot() const override;
};
