#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"

#include <iostream>
#include <map>

class ObjectNode : public Node
{
public:
    ObjectNode()
        : Node(NodeKind::OBJECT)
    {}

    std::string print() const override;

    static std::unique_ptr<ObjectNode> make_ptr();

    size_t child_count();

    void insert(std::string key, std::unique_ptr<Node> value);

    size_t height() const override;

    size_t node_count() const override;

    bool has_child(std::string value) const;

    Node* at(const std::string& key) const;

private:
    std::map<std::string, std::unique_ptr<Node>> _values;
};