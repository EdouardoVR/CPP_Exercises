#pragma once
#include "../lib/Unit.hpp"

#include <algorithm>
#include <set>
#include <string>
#include <utility>

class Kitchen
{
public:
    const Unit& register_unit(Unit unit);
    const Unit* find_unit(const std::string& name) const;

private:
    struct ElementNameComparer
    {
        using is_transparent = bool;

        bool operator()(const Unit& u1, const Unit& u2) const { return u1.name < u2.name; }
        bool operator()(const Unit& unit, const std::string& name) const { return unit.name < name; }
        bool operator()(const std::string& name, const Unit& unit) const { return name < unit.name; }
    };

    std::set<Unit, ElementNameComparer> _units;
};