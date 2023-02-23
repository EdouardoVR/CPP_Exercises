#include "StringLeaf.hpp"

std::string StringLeaf::print() const
{
    return "\"" + _value + "\"";
}

std::string StringLeaf::data()
{
    return _value;
}

std::unique_ptr<StringLeaf> StringLeaf::make_ptr(std::string value)
{
    return std::make_unique<StringLeaf>(value);
}

size_t StringLeaf::height() const
{
    return 0;
}

size_t StringLeaf::node_count() const
{
    return 1;
}