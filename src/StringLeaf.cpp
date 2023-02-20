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

std::unique_ptr<StringLeaf> StringLeaf::make_ptr(std::string value)
{
    return std::make_unique<StringLeaf>(value);
}