#pragma once

class Weapon {
public:
    virtual ~Weapon() = default;
    virtual void shoot() const = 0;
};