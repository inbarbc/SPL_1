#pragma once

#include "Party.h"
#include "Simulation.h"
#include <vector>

using std::vector;
using std::pair;

class JoinPolicy 
{
public:
    virtual void join(Party &party, Simulation &simulation) = 0; 
    virtual ~ JoinPolicy();
};

class MandatesJoinPolicy : public JoinPolicy
{
public:
    void join(Party &party, Simulation &simulation) override;
    virtual ~ MandatesJoinPolicy();
};

class LastOfferJoinPolicy : public JoinPolicy 
{
public:
    void join(Party &party, Simulation &simulation) override;
    virtual ~ LastOfferJoinPolicy();
};