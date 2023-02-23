#include "IntLeaf.hpp"

std::string IntLeaf::print() const
{
    return std::to_string(_value);
}

int IntLeaf::data()
{
    return _value;
}

std::unique_ptr<IntLeaf> IntLeaf::make_ptr(int data)
{
    return std::make_unique<IntLeaf>(data);
}

size_t IntLeaf::height() const
{
    return 0;
}

size_t IntLeaf::node_count() const
{
    return 1;
}