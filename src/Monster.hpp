#pragma once
#include <string>
#include <iostream>
#include "Card.hpp"

enum class Attribute
{
    Dark,
    Divine,
    Earth,
    Fire,
    Light,
    Water,
    Wind
};

std::string to_symbol(const Attribute attribute)
{
    switch (attribute)
    {
    case Attribute::Dark:
        return u8"闇";

    case Attribute::Divine:
        return u8"神";

    case Attribute::Earth:
        return u8"地";

    case Attribute::Fire:
        return u8"炎";

    case Attribute::Light:
        return u8"光";

    case Attribute::Water:
        return u8"水";

    case Attribute::Wind:
        return u8"風";
    }

    return "";
}

class Monster : public Card
{
public:
    Monster(const std::string &id, const std::string &name, Attribute attribut, const std::string &monster_type, int atk, int def)
        : Card{id, CardType::Monster}, _id{id}, _name{name}, _attribut{attribut}, _monster_type{monster_type}, _atk{atk}, _def{def}
    {
        set_name(_name);
    }

    Attribute
    get_attribute() const
    {
        return _attribut;
    }

    int get_atk() const
    {
        return _atk;
    }

    int get_def() const
    {
        return _def;
    }

    std::string get_description() const
    {
        return "[" + _monster_type + "]\n" +
               Card::get_description() + "\n"
                                         "ATK/" +
               std::to_string(_atk) + " DEF/" + std::to_string(_def);
    }

    std::string get_symbol() const
    {
        return to_symbol(_attribut);
    }

private:
    std::string _id;
    std::string _name;
    Attribute _attribut;
    std::string _monster_type;
    int _atk;
    int _def;
};