#pragma once
#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <iostream>

class StringLeaf : public Leaf
{
public:
    StringLeaf(std::string value)
        : Leaf(NodeKind::STRING)
        , _value { value } {};

    std::string print() const override;

    std::string data();

    static std::unique_ptr<StringLeaf> make_ptr(std::string value);

    size_t height() const override;

    size_t node_count() const override;

private:
    std::string _value;
};