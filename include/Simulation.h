#pragma once

#include <vector>
#include "Graph.h"
#include "Agent.h"
#include "Party.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const; // מחזיר הפנייה לגרף שאינו ניתן לשינוי
    const vector<Agent> &getAgents() const; // מחזיר הפנייה לרשימת הסוכנים הכללית שאינה ניתנת לשינוי
    const Party &getParty(int partyId) const; // מחזיר הפנייה למפלגה שאינה ניתנת לשינוי
    const vector<vector<int>> getPartiesByCoalitions() const;

    vector<int> &getCoalitions(); // מחזיר הפנייה לוקטור הקואליציות
    void addAgentToList(Agent &agent); // מוסיף סוכן לרשימת הסוכנים הכללית - במקרה בו מפלגה מצטרפת לקואליציה
    // void removeAgentFromList(Agent &agent); // מוחק סוכן מרשימת הסוכנים הכללית - במקרה בו לסוכן אין מפלגות אפשריות להציע להן להצטרף לקואליציה

private:
    Graph mGraph;
    vector<Agent> mAgents; 

    vector<int> mCoalitions;
};
