#pragma once
#include "Weapon.hpp"
#include <memory>

class WeaponDecorator : public Weapon {
protected:
    std::unique_ptr<Weapon> weapon_;
public:
    explicit WeaponDecorator(std::unique_ptr<Weapon> weapon);
    void shoot() const override;
};