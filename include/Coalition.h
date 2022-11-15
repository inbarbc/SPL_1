#pragma once

class Coalition
{
public:
    Coalition(int agentId, int mandates);
    int getAgentId() const;
    int getMandates() const;
    void addMandates();

private:
    int mAgentId;
    int mMandates;
};