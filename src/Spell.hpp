#pragma once
#include <iostream>
#include "Card.hpp"

enum class SpellType
{
    Normal,
    Equip,
    Continuous,
    QuickPlay,
    Field
};

std::string to_string(SpellType spell)
{
    switch (spell)
    {
    case SpellType::Normal:
        return "Normal";
    case SpellType::Equip:
        return "Equip";
    case SpellType::Continuous:
        return "Continuous";
    case SpellType::QuickPlay:
        return "Quick-Play";
    case SpellType::Field:
        return "Field";
    }
    return "";
}

class Spell : public Card
{
public:
    Spell(const std::string &id, const std::string &name, SpellType type)
        : Card(id, CardType::Spell), _id{id}, _type{type}
    {
        set_name(name);
        _symbol = u8"魔";
    };

    SpellType get_spell_type()
    {
        return _type;
    }

private:
    std::string _id;
    SpellType _type;
};