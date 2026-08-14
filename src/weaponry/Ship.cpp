#include "../../include/weaponry/Ship.hpp"
#include <iostream>

void Ship::equipWeapon(std::unique_ptr<Weapon> weapon) {
    equippedWeapon = std::move(weapon);
}

void Ship::shoot() const {
    if (equippedWeapon) {
        equippedWeapon->shoot();
        std::cout << std::endl;
    } else {
        std::cout << "Nenhuma arma equipada!" << std::endl;
    }
}

std::unique_ptr<Weapon> Ship::unequipWeapon() {
    return std::move(equippedWeapon);
}
