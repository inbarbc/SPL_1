#pragma once

#include "Coalition.h"
#include <vector>

using std::vector;

class JoinPolicy
{
public:
    JoinPolicy(vector<Coalition> coalitions); 

private:
    vector<Coalition> mCoalitions;
};

class MandatesJoinPolicy : public JoinPolicy
{
public:
    MandatesJoinPolicy();
    void join();

};

class LastOfferJoinPolicy : public JoinPolicy 
{
public:
    LastOfferJoinPolicy();
    void join();
};