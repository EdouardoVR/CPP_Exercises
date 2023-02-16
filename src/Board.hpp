#pragma once
#include <vector>
#include "Monster.hpp"
#include "Spell.hpp"
#include "Trap.hpp"

class Board
{

public:
    bool put(std::unique_ptr<Monster> monster)
    {
        if (_monsters < 5)
        {
            _cards.emplace_back(std::move(monster));
            _monsters += 1;
            return true;
        }
        return false;
    }

    bool put(std::unique_ptr<Spell> spell)
    {
        if (_spells + _trap < 5)
        {
            _cards.emplace_back(std::move(spell));
            _spells += 1;
            return true;
        }
        return false;
    }

    bool put(std::unique_ptr<Trap> trap)
    {
        if (_trap + _spells < 5)
        {
            _cards.emplace_back(std::move(trap));
            _trap += 1;
            return true;
        }
        return false;
    }

private:
    std::vector<std::unique_ptr<Card>> _cards;
    int _monsters = 0;
    int _spells = 0;
    int _trap = 0;
};