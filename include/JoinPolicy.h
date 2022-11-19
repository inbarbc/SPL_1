#pragma once

#include "Agent.h"
#include "Party.h"
#include <vector>

using std::vector;
using std::pair;

class JoinPolicy 
{
public:
    virtual void join(Party &party, vector<int> &coalitions,vector<Agent> &allAgents, vector<int> &myAgents) = 0; 
protected:
    Agent *mSelectedAgent; 
};

class MandatesJoinPolicy : public JoinPolicy
{
public:
    void join(Party &party, vector<int> &coalitions,vector<Agent> &allAgents, vector<int> &myAgents);
};

class LastOfferJoinPolicy : public JoinPolicy 
{
public:
    void join(Party &party, vector<int> &coalitions,vector<Agent> &allAgents, vector<int> &myAgents);
};