#include "../../include/weaponry/WeaponDecorator.hpp"

WeaponDecorator::WeaponDecorator(std::unique_ptr<Weapon> weapon) : weapon_(std::move(weapon)) {}

void WeaponDecorator::shoot() const {
    if (weapon_) {
        weapon_->shoot();
    }
}
