#pragma once

class Plush
{
public:
    Plush() {}
    Plush(int _cost) : cost{_cost} {}
    int get_cost() const
    {
        return cost;
    }

    int set_cost(int value)
    {
        cost = value;
        return get_cost();
    }

private:
    int cost = 10;
};