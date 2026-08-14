#include "../../include/weaponry/BaseWeapons.hpp"
#include <iostream>

void ContinuousLaser::shoot() const {
    std::cout << "Atirando laser contínuo...";
}

void MissileSwarm::shoot() const {
    std::cout << "Atirando enxame de mísseis...";
}
