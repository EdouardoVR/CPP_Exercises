#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"

#include <vector>

class ArrayNode : public Node
{
public:
    NodeKind kind();

    std::string print() const override;
};