#pragma once
#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <string>

class IntLeaf : public Leaf
{
public:
    IntLeaf(int value)
        : _value { value } {};

    std::string print() const override;

    NodeKind kind();

    int data();

    static std::unique_ptr<IntLeaf> make_ptr(int value);

private:
    int _value;
};