#include "IntLeaf.hpp"

std::string IntLeaf::print() const
{
    return std::to_string(_value);
}

NodeKind IntLeaf::kind()
{
    return NodeKind::INT;
}

int IntLeaf::data()
{
    return _value;
}

std::unique_ptr<IntLeaf> IntLeaf::make_ptr(int value)
{
    return std::make_unique<IntLeaf>(value);
}