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
        result += v.second->node_count();
    }
    return result + 1;
}

bool ObjectNode::has_child(std::string value) const
{
    for (auto& v : _values)
    {
        if (v.first == value)
        {
            return true;
        }
    }
    return false;
}

Node* ObjectNode::at(const std::string& key) const
{
    if (ObjectNode::has_child(key))
        return _values.at(key).get();
    else
        return nullptr;
}