#include "ObjectNode.hpp"

NodeKind ObjectNode::kind()
{
    return NodeKind::OBJECT;
}

std::string ObjectNode::print() const
{
    std::string result = "{";
    bool        first  = true;
    for (auto const& el : _nodes)
    {
        if (first)
            first = false;
        else
            result += ",";
        result += '"' + el.first + "\":";
        result += el.second->print();
    }
    result += '}';
    return result;
}

std::unique_ptr<ObjectNode> ObjectNode::make_ptr()
{
    auto result    = std::make_unique<ObjectNode>();
    result->_nodes = std::map<std::string, NodePtr>();
    return result;
}