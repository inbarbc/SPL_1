#pragma once

//#include "Party.h"
//#include "Graph.h"
//#include "Agent.h"
#include <vector>

class Party;
class Graph;
class Agent;

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
    virtual void select(const Graph &graph, Agent &agent, vector<Party> &parties);
};

class EdgeWeightSelectionPolicy: public SelectionPolicy
{
public:
    virtual void select(const Graph &graph, Agent &agent, vector<Party> &parties);
};