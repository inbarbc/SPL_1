#pragma once

#include "Party.h"
#include "Agent.h"
#include <vector>

using std::vector;

class SelectionPolicy
{
public:
    Party *mSelectedParty;
    virtual void select(const Graph &graph, Agent &agent, vector<Party> &parties) = 0;
};

class MandatesSelectionPolicy: public SelectionPolicy
{ 
public:
    void select(const Graph &graph, Agent &agent, vector<Party> &parties);
};

class EdgeWeightSelectionPolicy: public SelectionPolicy
{
public:
    void select(const Graph &graph, Agent &agent, vector<Party> &parties);
};