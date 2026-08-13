#pragma once

class CrewMemberDuty {
public:
    virtual ~CrewMemberDuty() = default;
    virtual void execute() = 0;
};