#pragma once

#include "Party.h"
#include "Agent.h"
#include "Graph.h"
#include <vector>

using std::vector;

class SelectionPolicy
{
public:
    virtual void select(Graph &graph, Agent &agent, vector<int> &parties) = 0;
protected:
    Party *mSelectedParty;
};

class MandatesSelectionPolicy: public SelectionPolicy
{ 
public:
    void select(Graph &graph, Agent &agent, vector<int> &parties);
};

class EdgeWeightSelectionPolicy: public SelectionPolicy
{
public:
    void select(Graph &graph, Agent &agent, vector<int> &parties);
};