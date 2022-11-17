#pragma once

#include <string>
#include <vector>
#include "Agent.h"
#include "Simulation.h"
#include "JoinPolicy.h"

using std::string;
using std::vector;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;

    const vector<Agent> getAgents() const; // list of agents who suggested this party
    void addAgentToList(Agent &agent);
    const int getId() const;
    bool checkOffersFromCoalition(const int coalitionsId) const;

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int mTimer;
    vector<Agent> mAgents;
    vector<bool> mCoalitions;
};
