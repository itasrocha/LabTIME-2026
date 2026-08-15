#include "../../include/contingency/EnergyCore.hpp"
#include <algorithm>


EnergyCore::EnergyCore() : energyLevel(100) {}

void EnergyCore::attachObserver(std::shared_ptr<EnergyCoreObserver> observer) {
    this->observers.push_back(observer);
}

void EnergyCore::detachObserver(std::shared_ptr<EnergyCoreObserver> observer) {
    this->observers.erase(
        std::remove_if(observers.begin(), observers.end(),
            [&observer](const std::weak_ptr<EnergyCoreObserver>& weak_ptr) {
                return weak_ptr.expired() || weak_ptr.lock() == observer;
            }),
        observers.end()
    );
}

void EnergyCore::notifyObservers() {
    for (auto iterator = observers.begin(); iterator != observers.end(); ) {
        if (auto observer = iterator->lock()) {
            observer->update();
            iterator++;
        } else {
            iterator = observers.erase(iterator);
        }
    }
}

int EnergyCore::getEnergy() const {return energyLevel;}

void EnergyCore::drainEnergy(unsigned int amount) {
    this->energyLevel -= amount;
    if (this->energyLevel < 0) energyLevel = 0;
    if (this->energyLevel < 30 && this->energyLevel + amount >= 30) notifyObservers();
}