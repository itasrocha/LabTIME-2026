#pragma once
#include "Weapon.hpp"
#include <iostream>

class ContinuousLaser : public Weapon {
public:
    void shoot() const override;
};

class MissileSwarm : public Weapon {
public:
    void shoot() const override;
};
