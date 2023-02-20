#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"

#include <vector>

class ArrayNode : public Node
{
public:
    NodeKind kind() { return NodeKind::ARRAY; }

    std::string print() const { return "[]"; }
};