#pragma once
#include "Weapon.hpp"
#include <memory>

/**
 * @class Ship
 * @brief Representa a nave espacial capaz de equipar e disparar armas.
 * 
 * Atua como o cliente que utiliza o componente Weapon (e seus decoradores).
 */
class Ship {
private:
    std::unique_ptr<Weapon> equippedWeapon; ///< A arma equipada atualmente.

public:
    /**
     * @brief Equipa uma arma na nave.
     * @param weapon A arma a ser equipada.
     */
    void equipWeapon(std::unique_ptr<Weapon> weapon);

    /**
     * @brief Dispara a arma atualmente equipada.
     */
    void shoot() const;

    /**
     * @brief Desequipa a arma atual.
     * @return A arma previamente equipada.
     */
    std::unique_ptr<Weapon> unequipWeapon();
};