#pragma once

#include <vector>
#include "Graph.h"
#include "Simulation.h"
#include "SelectionPolicy.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    const vector<Party> getParties() const;
    SelectionPolicy *getSelectionPolicy() const;

    void addPartyToList(const Party &party);
    void removePartyFromList(const Party &party);
    const int getCoalitionId() const;
    void setCoalitionId(int coalitionId);


private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    vector<Party> mParties;
    int mCoalitionId;
};
