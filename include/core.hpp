#pragma once

class EnergyCore {
private:
    int energyLevel;
public:
    EnergyCore(int energyLevel);
    int getEnergy() const;
    void drainEnergy(int amount);
};
