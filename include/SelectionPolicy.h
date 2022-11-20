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
    virtual ~SelectionPolicy();
//protected:
//    Party *mSelectedParty;
};

class MandatesSelectionPolicy: public SelectionPolicy
{ 
public:
    virtual void select(Graph &graph, Agent &agent, vector<int> &parties);
    virtual ~MandatesSelectionPolicy();
};

class EdgeWeightSelectionPolicy: public SelectionPolicy
{
public:
    virtual void select(Graph &graph, Agent &agent, vector<int> &parties);
    virtual ~EdgeWeightSelectionPolicy();
};