#pragma once
#include "Weapon.hpp"

/**
 * @class ContinuousLaser
 * @brief Componente concreto representando uma arma de laser contínuo.
 */
class ContinuousLaser : public Weapon {
public:
    /**
     * @brief Dispara o laser contínuo.
     */
    void shoot() const override;
};

/**
 * @class MissileSwarm
 * @brief Componente concreto representando uma arma de enxame de mísseis.
 */
class MissileSwarm : public Weapon {
public:
    /**
     * @brief Dispara o enxame de mísseis.
     */
    void shoot() const override;
};
