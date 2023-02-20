#include "ArrayNode.hpp"

NodeKind ArrayNode::kind()
{
    return NodeKind::ARRAY;
}

std::string ArrayNode::print() const
{
    std::string result = "[";
    for (unsigned i = 0; i < _nodes.size(); ++i)
    {
        if (i > 0)
            result += ",";
        result += _nodes[i]->print();
    }
    result += ']';
    return result;
}

std::unique_ptr<ArrayNode> ArrayNode::make_ptr()
{
    auto result    = std::make_unique<ArrayNode>();
    result->_nodes = std::vector<NodePtr>();
    return result;
}