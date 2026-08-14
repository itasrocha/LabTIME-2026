#pragma once
#include "Weapon.hpp"
#include <memory>

/**
 * @class WeaponDecorator
 * @brief Classe base decoradora para modificações de armas.
 * 
 * Implementa o padrão Decorator para adicionar comportamentos adicionais
 * a uma Weapon dinamicamente em tempo de execução.
 */
class WeaponDecorator : public Weapon {
protected:
    std::unique_ptr<Weapon> weapon_; ///< A instância da arma encapsulada.
public:
    /**
     * @brief Constrói um WeaponDecorator encapsulando outra arma.
     * @param weapon Ponteiro único para a arma a ser decorada.
     */
    explicit WeaponDecorator(std::unique_ptr<Weapon> weapon);

    /**
     * @brief Dispara a arma, delegando para a arma encapsulada.
     */
    void shoot() const override;
};