#pragma once
#include "CrewMemberDuty.hpp"
#include <string>
#include <memory>

class CrewMember {
private:
    std::string name;
    std::unique_ptr<CrewMemberDuty> duty;
public:
    CrewMember(std::string name, std::unique_ptr<CrewMemberDuty> duty);
    void changeDuty(std::unique_ptr<CrewMemberDuty> duty);
    void work();
};