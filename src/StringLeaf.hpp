#pragma once
#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <iostream>
#include <string>

class StringLeaf : public Leaf
{
public:
    StringLeaf(std::string value)
        : _value { value } {};

    NodeKind kind() { return NodeKind::STRING; }

private:
    std::string _value;
};