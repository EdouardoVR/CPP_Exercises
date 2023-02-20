#pragma once
#include "InstanceCounter.hpp"

#include <iostream>

class Node : public InstanceCounter
{
protected:
    Node() {};

public:
    virtual ~Node() {};
    virtual std::string print() const = 0;
};

using NodePtr = std::unique_ptr<Node>;