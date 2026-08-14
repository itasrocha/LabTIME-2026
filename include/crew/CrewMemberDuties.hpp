#pragma once
#include "CrewMemberDuty.hpp"
#include <iostream>
#include <ostream>

class CannonOpertatorDuty: public CrewMemberDuty {
public:
    void execute() override;
};

class EngineMechanicDuty: public CrewMemberDuty {
public:
    void execute() override;
};

class IdleDuty: public CrewMemberDuty {
public:
    void execute() override;
};