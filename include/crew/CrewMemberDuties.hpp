#pragma once
#include "CrewMemberDuty.hpp"
#include <iostream>
#include <ostream>

class CannonOpertatorDuty: public CrewMemberDuty {
public:
    void execute() override {
        std::cout << "Operando canhões!" << std::endl;
    }
};

class EngineMechanicDuty: public CrewMemberDuty {
public:
    void execute() override {
        std::cout << "Consertando motores!" << std::endl;
    }
};

class IdleDuty: public CrewMemberDuty {
public:
    void execute() override {
        std::cout << "Que tédio" << std::endl;
    }
};