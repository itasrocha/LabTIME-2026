#include "../include/core.hpp"


EnergyCore::EnergyCore(int energyLevel) : energyLevel(energyLevel) {}

int EnergyCore::getEnergy() const {return energyLevel;}

void EnergyCore::drainEnergy(int amount) {energyLevel -= amount;}