#pragma once
#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <iostream>

class IntLeaf : public Leaf
{
public:
    IntLeaf(int value)
        : Leaf(NodeKind::INT)
        , _value { value } {};

    std::string print() const override;

    int data();

    static std::unique_ptr<IntLeaf> make_ptr(int data);

    size_t height() const override;

    size_t node_count() const override;

private:
    int _value;
};