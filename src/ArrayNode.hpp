#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"

#include <iostream>
#include <vector>

class ArrayNode : public Node
{
public:
    ArrayNode()
        : Node(NodeKind::ARRAY)
    {}

    std::string print() const override;

    static std::unique_ptr<ArrayNode> make_ptr();

    int child_count();

    void push_back(std::unique_ptr<Node> value);

    size_t height() const override;

    size_t node_count() const override;

private:
    std::vector<std::unique_ptr<Node>> _nodes;
};