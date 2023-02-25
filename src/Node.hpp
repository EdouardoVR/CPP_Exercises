#pragma once
#include "InstanceCounter.hpp"
#include "NodeKind.hpp"

#include <iostream>

class IntLeaf;
class StringLeaf;
class ArrayNode;
class ObjectNode;

class Node;

using NodePtr = std::unique_ptr<Node>;

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
    IntLeaf*            as_IntLeaf();
    StringLeaf*         as_StringLeaf();
    ArrayNode*          as_ArrayNode();
    ObjectNode*         as_ObjectNode();

    const IntLeaf*    as_IntLeaf() const;
    const StringLeaf* as_StringLeaf() const;
    const ArrayNode*  as_ArrayNode() const;
    const ObjectNode* as_ObjectNode() const;

private:
    const NodeKind _kind;
};