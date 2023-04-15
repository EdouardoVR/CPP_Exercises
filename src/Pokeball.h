#pragma once
#include "Pokemon.h"

// A ball where a Pokemon sleeps.
class Pokeball
{
public:
    Pokeball() = default;

    bool empty() const
    {
        return _pokemon == nullptr;
    }

    void store(PokemonPtr pokemon)
    {
        if (empty())
        {
            _pokemon = std::move(pokemon);
        }
    }

    const Pokemon &pokemon() const
    {
        return *_pokemon;
    }

    PokemonPtr steal()
    {
        return std::move(_pokemon);
    }

private:
    PokemonPtr _pokemon;
};
