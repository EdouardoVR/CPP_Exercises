#pragma once
#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <string>

class IntLeaf : public Leaf
{
public:
    IntLeaf(int value)
        : _value { value } {};

    int value() override { return _value; }

    NodeKind kind() { return NodeKind::INT; }

    std::string print() override { return std::to_string(_value); }

    int data() { return _value; }

private:
    int _value;
};