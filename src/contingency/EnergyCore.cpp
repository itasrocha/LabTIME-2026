#include "../../include/contingency/EnergyCore.hpp"
#include <algorithm>


EnergyCore::EnergyCore() : energyLevel(100) {}

void EnergyCore::attachObserver(EnergyCoreObserver* observer) {
    this->observers.push_back(observer);
}

void EnergyCore::detachObserver(EnergyCoreObserver* observer) {
    this->observers.erase(
        std::remove(observers.begin(), observers.end(), observer),
        observers.end()
    );
}

void EnergyCore::notifyObservers() {
    for (auto* observer: observers) {
        observer->update();
    }
}

int EnergyCore::getEnergy() const {return energyLevel;}

void EnergyCore::drainEnergy(int amount) {
    this->energyLevel -= amount;
    if (this->energyLevel < 0) energyLevel = 0;
    if (this->energyLevel < 30 && this->energyLevel + amount >= 30) notifyObservers();
}