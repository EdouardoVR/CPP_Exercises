#include "Kitchen.hpp"

const Unit& Kitchen::register_unit(Unit unit)
{
    auto [it, emplaced] = _units.emplace(std::move(unit));
    return *it;
}

const Unit* Kitchen::find_unit(const std::string& name) const
{
    const auto it = _units.find(name);
    return it != _units.end() ? &(*it) : nullptr;
}