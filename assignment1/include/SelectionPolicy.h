#pragma once

#include "Party.h"
#include "Agent.h"
#include "Graph.h"
#include <vector>

using std::vector;

class Party;
class Agent;
class Graph;

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