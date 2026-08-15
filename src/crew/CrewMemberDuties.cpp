#include "../../include/crew/CrewMemberDuties.hpp"
#include <iostream>

void CannonOpertatorDuty::execute() {
    std::cout << "Disparando os canhões!" << std::endl;
}

void EngineMechanicDuty::execute() {
    std::cout << "Consertando os motores!" << std::endl;
}

void IdleDuty::execute() {
    std::cout << "Que tédio, não tenho nada pra fazer." << std::endl;
}
