#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"

#include <vector>

class ArrayNode : public Node
{
public:
    NodeKind kind();

    std::string print() const override;

    static std::unique_ptr<ArrayNode> make_ptr();

private:
    std::vector<NodePtr> _nodes;
};