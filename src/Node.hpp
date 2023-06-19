#pragma once
#include "InstanceCounter.hpp"

#include <iostream>
#include <string>

class Node : public InstanceCounter
{
protected:
    Node() = default;

public:
    virtual ~Node() = default;

    virtual std::string print() = 0;
};