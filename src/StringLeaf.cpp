#include "StringLeaf.hpp"

std::string StringLeaf::print() const
{
    return "\"" + _value + "\"";
}

NodeKind StringLeaf::kind()
{
    return NodeKind::STRING;
}

std::string StringLeaf::data()
{
    return _value;
}