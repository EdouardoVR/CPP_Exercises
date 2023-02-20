#pragma once
#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <string>

class IntLeaf : public Leaf
{
public:
    IntLeaf(int value)
        : _value { value } {};

    std::string print() const override { return std::to_string(_value); }

    NodeKind kind() { return NodeKind::INT; }

    int data() { return _value; }

    static NodePtr make_ptr(int value) { return std::make_unique<IntLeaf>(value); }

private:
    int _value;
};