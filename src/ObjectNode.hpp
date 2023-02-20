#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"

#include <map>

class ObjectNode : public Node
{
public:
    NodeKind kind();

    std::string print() const override;

    static std::unique_ptr<ObjectNode> make_ptr();

private:
    std::map<std::string, NodePtr> _nodes;
};