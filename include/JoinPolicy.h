#pragma once

#include "Agent.h"
#include <vector>

using std::vector;
using std::pair;

class JoinPolicy 
{
public:
    Agent *mSelectedAgent; 
    virtual void join(vector<int> &coalitions, vector<Agent> &agents) = 0; 
};

class MandatesJoinPolicy : public JoinPolicy
{
public:
    virtual void join(vector<int> &coalitions, vector<Agent> &agents);
};

class LastOfferJoinPolicy : public JoinPolicy 
{
public:
    virtual void join(vector<int> &coalitions, vector<Agent> &agents);
};