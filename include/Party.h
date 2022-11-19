#pragma once

#include <string>
#include <vector>
#include "Agent.h"
#include "JoinPolicy.h"

using std::string;
using std::vector;

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

    const vector<Agent> &getAgents() const;  // return a pointer to a vector of agents who offer this party to join them
    void addAgentToList(const Agent &agent);
    const int getId() const;
    const bool offerChecking(const int coalitionsId) const;
    void offerMarking (const int coalitionsId);

    virtual ~ Party(); //destructor
    Party(const Party &other); //copy constructor
    Party &operator=(const Party &other); //copy assignment operator
    Party(Party &&other); //move constructor
    Party &operator=(Party && other); //move assignment operator

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
