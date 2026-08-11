#pragma once

class EnergyCoreObserver{
public:
    virtual void update() = 0;
    virtual ~EnergyCoreObserver() = default;
};