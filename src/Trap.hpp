#pragma once
#include <iostream>
#include "Card.hpp"

enum class TrapType
{
    Normal,
    Continuous,
    Counter
};

std::string to_string(TrapType trap)
{
    switch (trap)
    {
    case TrapType::Normal:
        return "Normal";
    case TrapType::Continuous:
        return "Continuous";
    case TrapType::Counter:
        return "Counter";
    }
    return "";
}

class Trap : public Card
{
public:
    Trap(std::string id, std::string name, TrapType type) : Card(id, CardType::Trap), _id{id}, _type{type}
    {
        set_name(name);
    }

    TrapType get_trap_type()
    {
        return _type;
    }

    std::string get_symbol() const
    {
        return to_string(_type);
    }

private:
    std::string _id;
    TrapType _type;
};