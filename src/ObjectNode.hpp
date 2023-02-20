#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"

class ObjectNode : public Node
{
public:
    NodeKind kind();

    std::string print() const override;
};