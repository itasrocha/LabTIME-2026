#pragma once
#include "CrewMemberDuty.hpp"
#include <iostream>
#include <ostream>

/**
 * @class CannonOpertatorDuty
 * @brief Estratégia concreta representando a função de operar canhões.
 */
class CannonOpertatorDuty: public CrewMemberDuty {
public:
    /**
     * @brief Executa a função de operador de canhões.
     */
    void execute() override;
};

/**
 * @class EngineMechanicDuty
 * @brief Estratégia concreta representando a função de mecânico do motor.
 */
class EngineMechanicDuty: public CrewMemberDuty {
public:
    /**
     * @brief Executa a função de mecânico do motor.
     */
    void execute() override;
};

/**
 * @class IdleDuty
 * @brief Estratégia concreta representando um estado ocioso.
 */
class IdleDuty: public CrewMemberDuty {
public:
    /**
     * @brief Executa a função ociosa.
     */
    void execute() override;
};