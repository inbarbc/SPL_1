#pragma once

class Coalition
{
    public:
        Coalition(int agentId,int mandates);
        int getMandates() const;
        void setMandates(int mandates);

    private:
        int mMandates;
        int mAgentId;
};