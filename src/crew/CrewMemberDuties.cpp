#include "../../include/crew/CrewMemberDuties.hpp"
#include <iostream>

void CannonOpertatorDuty::execute() {
    std::cout << "Operando canhões!" << std::endl;
}

void EngineMechanicDuty::execute() {
    std::cout << "Consertando motores!" << std::endl;
}

void IdleDuty::execute() {
    std::cout << "Que tédio" << std::endl;
}
