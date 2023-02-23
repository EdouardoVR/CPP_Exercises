#include "ObjectNode.hpp"

std::string ObjectNode::print() const
{
    std::string result = "{";
    bool        first  = true;
    for (auto const& el : _values)
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
    return std::make_unique<ObjectNode>();
}

size_t ObjectNode::child_count()
{
    return _values.size();
}

void ObjectNode::insert(std::string key, std::unique_ptr<Node> value)
{
    _values.insert({ key, std::move(value) });
}

size_t ObjectNode::height() const
{
    size_t result = 0;
    for (auto& v : _values)
    {
        if (v.second->height() + 1 > result)
        {
            result = v.second->height() + 1;
        }
    }
    return result;
}

size_t ObjectNode::node_count() const
{
    size_t result = 0;
    for (auto& v : _values)
    {
        result += 1;
        result += v.second->node_count();
    }
    return result;
}