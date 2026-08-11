#pragma once
#include <vector>
#include "EnergyCoreObserver.hpp"

class EnergyCore {
private:
    int energyLevel;
    std::vector<EnergyCoreObserver*> observers;
public:
    EnergyCore();
    void attachObserver(EnergyCoreObserver* observer);
    void detachObserver(EnergyCoreObserver* observer);
    void notifyObservers();
    int getEnergy() const;
    void drainEnergy(int amount);
};
