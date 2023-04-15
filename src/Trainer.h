#pragma once
#include <iostream>
#include "PC.h"
#include "Pokeball.h"
#include "Pokedex.h"
#include "Pokemon.h"
#include <array>
#include <algorithm>

// A person that captures Pokemons and makes them fight.
class Trainer
{
public:
    Trainer(const std::string &name, PC &pc) : _name{name}, _pc{pc} {}

    const std::string &name() const
    {
        return _name;
    }

    PC &pc() const
    {
        return _pc;
    }

    const std::array<Pokeball, 6> &pokeballs() const
    {
        return _pokeballs;
    }

    void capture(PokemonPtr pokemon)
    {
        pokemon->set_trainer(*this);
        for (auto &p : _pokeballs)
        {
            if (p.empty())
            {
                p.store(std::move(pokemon));
                return;
            }
        }
        _pc.transfer(std::move(pokemon));
    }

    void store_in_pc(size_t id)
    {
        _pc.transfer(_pokeballs[id].steal());
    }

    void fetch_from_pc(const std::string &name)
    {
        for (auto &pokeball : _pokeballs)
        {
            if (pokeball.empty())
            {
                auto pokemon = _pc.steal(*this, name);
                if (pokemon != nullptr)
                {
                    pokeball.store(std::move(pokemon));
                }

                return;
            }
        }
    }

private:
    std::string _name;
    PC &_pc;
    std::array<Pokeball, 6> _pokeballs;
};
