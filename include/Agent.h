#pragma once

#include <vector>
#include "Graph.h"
#include "SelectionPolicy.h"

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);

    const vector<Party> &getParties() const; // מחזיר הפנייה לרשימת המפלגות האפשריות
    SelectionPolicy *getSelectionPolicy() const; // מחזיר כתובת של אופן הבחירה של הסוכן
    void addPartyToList(const Party &party); // עבור שכפול סוכן
    void removePartyFromList(const Party &party); // במקרה בו לא קיימות מפלגות רלוונטיות להציע להן להצטרף לקואליציה
    const int getCoalitionId() const;
    void setCoalitionId(int coalitionId);


private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    
    vector<Party> mParties;
    int mCoalitionId;
};
