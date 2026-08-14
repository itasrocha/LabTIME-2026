#pragma once
#include <iostream>
#include "EnergyCoreObserver.hpp"

class ShieldSystem : public EnergyCoreObserver {
public:
    void update() override;
};

class LightSystem : public EnergyCoreObserver {
public:
    void update() override;
};

class PanelSystem : public EnergyCoreObserver {
public:
    void update() override;
};