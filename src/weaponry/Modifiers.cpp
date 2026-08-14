#include "../../include/weaponry/Modifiers.hpp"
#include <iostream>

FireDamageModifier::FireDamageModifier(std::unique_ptr<Weapon> weapon) : WeaponDecorator(std::move(weapon)) {}

void FireDamageModifier::shoot() const {
    WeaponDecorator::shoot();
    std::cout << " [+ Dano de Fogo]";
}

ArmorPiercingModifier::ArmorPiercingModifier(std::unique_ptr<Weapon> weapon) : WeaponDecorator(std::move(weapon)) {}

void ArmorPiercingModifier::shoot() const {
    WeaponDecorator::shoot();
    std::cout << " [+ Dano Perfurante]";
}
