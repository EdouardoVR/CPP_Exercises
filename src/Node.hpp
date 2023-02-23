#pragma once
#include "InstanceCounter.hpp"
#include "NodeKind.hpp"

#include <iostream>

class Node : public InstanceCounter
{
protected:
    Node(NodeKind kind)
        : _kind { kind } {};

public:
    virtual ~Node()                   = default;
    virtual std::string print() const = 0;
    NodeKind            kind() const;
    virtual size_t      height() const     = 0;
    virtual size_t      node_count() const = 0;

private:
    const NodeKind _kind;
};