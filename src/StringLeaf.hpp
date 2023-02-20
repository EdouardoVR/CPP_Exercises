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

    std::string print() const override;

    NodeKind kind();

    std::string data();

private:
    std::string _value;
};