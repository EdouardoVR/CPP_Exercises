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

    std::string print() const override { return "\"" + _value + "\""; }

    NodeKind kind() { return NodeKind::STRING; }

    std::string data() { return _value; }

    static NodePtr make_ptr(std::string value) { return std::make_unique<StringLeaf>(value); }

private:
    std::string _value;
};