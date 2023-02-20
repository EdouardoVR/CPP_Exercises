#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"

class ObjectNode : public Node
{
public:
    NodeKind kind() { return NodeKind::OBJECT; }

    std::string print() const { return "{}"; }
};