#pragma once

#include <string>
#include <vector>
#include "Agent.h"
#include "JoinPolicy.h"

using std::string;
using std::vector;

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

    const vector<Agent> &getAgents() const;  // מחזיר הפנייה לוקטור הסוכנים שהציעו למפלגה זו
    void addAgentToList(const Agent &agent);
    const int getId() const;
    const bool offerChecking(const int coalitionsId) const;
    void offerMarking (const int coalitionsId);

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
