#pragma once
#include "WeaponDecorator.hpp"
#include <iostream>

class FireDamageModifier : public WeaponDecorator {
public:
    explicit FireDamageModifier(std::unique_ptr<Weapon> weapon);
    void shoot() const override;
};

class ArmorPiercingModifier : public WeaponDecorator {
public:
    explicit ArmorPiercingModifier(std::unique_ptr<Weapon> weapon);
    void shoot() const override;
};
