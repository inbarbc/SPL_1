#pragma once

#include <stack>

using std::stack;


class JoinPolicy {};

class MandatesJoinPolicy : public JoinPolicy
{
public:
    MandatesJoinPolicy();
    void join(stack<Coalition> coalitions);
};

class LastOfferJoinPolicy : public JoinPolicy 
{
public:
    LastOfferJoinPolicy();
    void join(stack<Coalition> coalitions);
};