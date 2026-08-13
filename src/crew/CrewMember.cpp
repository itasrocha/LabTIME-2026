#include "../../include/crew/CrewMember.hpp"
#include <memory>
#include <string>
#include <utility>

CrewMember::CrewMember(std::string name, std::unique_ptr<CrewMemberDuty> duty) : name(name), duty(std::move(duty)) {}

void CrewMember::changeDuty(std::unique_ptr<CrewMemberDuty> duty) {
    this->duty = std::move(duty);
}

void CrewMember::work() {
    duty->execute();
}