#pragma once
#include "Weapon.hpp"
#include <memory>

class Ship {
private:
    std::unique_ptr<Weapon> equippedWeapon;

public:
    void equipWeapon(std::unique_ptr<Weapon> weapon);
    void shoot() const;
    std::unique_ptr<Weapon> unequipWeapon();
};