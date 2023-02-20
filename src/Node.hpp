#pragma once
#include "InstanceCounter.hpp"

#include <iostream>

class Node : public InstanceCounter
{
protected:
    Node() {};

public:
    virtual ~Node() {};
    virtual int         value() = 0;
    virtual std::string print() = 0;
};