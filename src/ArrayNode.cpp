#include "ArrayNode.hpp"

std::string ArrayNode::print() const
{
    std::string result = "[";
    for (size_t i = 0; i < _nodes.size(); i++)
    {
        result += _nodes[i]->print();
        if (i != _nodes.size() - 1)
        {
            result += ",";
        }
    }
    result += "]";
    return result;
}

std::unique_ptr<ArrayNode> ArrayNode::make_ptr()
{
    return std::make_unique<ArrayNode>();
}

int ArrayNode::child_count()
{
    return _nodes.size();
}

void ArrayNode::push_back(std::unique_ptr<Node> value)
{
    _nodes.push_back(std::move(value));
}

size_t ArrayNode::height() const
{
    size_t result = 0;
    for (size_t i = 0; i < _nodes.size(); i++)
    {
        if (_nodes[i]->height() + 1 > result)
        {
            result = _nodes[i]->height() + 1;
        }
    }
    return result;
}

size_t ArrayNode::node_count() const
{
    size_t result = 0;
    for (size_t i = 0; i < _nodes.size(); i++)
    {
        result += 1;
        result += _nodes[i]->node_count();
    }
    return result;
}