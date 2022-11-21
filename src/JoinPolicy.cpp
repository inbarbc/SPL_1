#include "../include/JoinPolicy.h"
#include "Agent.h"
#include "Graph.h"

JoinPolicy* MandatesJoinPolicy::clone() const
{
    return new MandatesJoinPolicy();
}

JoinPolicy* LastOfferJoinPolicy::clone() const
{
    return new LastOfferJoinPolicy();
}

void MandatesJoinPolicy::join(Party &party, Simulation &simulation)
{
    // select agent
    int m = 0;
    Agent *mSelectedAgent = &simulation.getAgents()[party.getAgents()[0]];

    for (int agent : party.getAgents())
    {
        if (simulation.getCoalitions()[(*mSelectedAgent).getCoalitionId()] > m)
        {
            m = simulation.getCoalitions()[(*mSelectedAgent).getCoalitionId()];
            mSelectedAgent = &simulation.getAgents()[party.getAgents()[agent]];
        }
    }

    // update coalition
    simulation.getCoalitions()[(*mSelectedAgent).getCoalitionId()] += party.getMandates();

    // update party
    party.setState(Joined);

    // clone agent
    Agent clonedAgent = Agent(*mSelectedAgent,simulation.getAgents().size(),party.getId());
    Graph &graph = simulation.getGraph();
    for (int i = 0; i <= graph.getNumVertices(); i++)
    {
        if (graph.getEdgeWeight(party.getId(),i) > 0)
        {
            if ((graph.getParty(i).getState() != Joined) & (!graph.getParty(i).offerChecking(clonedAgent.getCoalitionId())))
            {
                clonedAgent.addParty(i);
            }
        }
    }  
    simulation.addAgent(clonedAgent);
}

void LastOfferJoinPolicy::join(Party &party, Simulation &simulation)
{
    // select agent
    Agent *mSelectedAgent = &simulation.getAgents()[party.getAgents().back()];

    // update coalition
    simulation.getCoalitions()[(*mSelectedAgent).getCoalitionId()] += party.getMandates();

    // update party
    party.setState(Joined);

    // clone agent
    Agent clonedAgent = Agent(*mSelectedAgent,simulation.getAgents().size(),party.getId());
    Graph &graph = simulation.getGraph();
    for (int i = 0; i <= graph.getNumVertices(); i++)
    {
        if (graph.getEdgeWeight(party.getId(),i) > 0)
        {
            if ((graph.getParty(i).getState() != Joined) & (!graph.getParty(i).offerChecking(clonedAgent.getCoalitionId())))
            {
                clonedAgent.addParty(i);
            }
        }
    }  
    simulation.addAgent(clonedAgent);
}