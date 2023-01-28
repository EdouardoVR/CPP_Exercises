#pragma once
#include <string>
#include <iostream>
#include <PlushStore.hpp>

class Kid
{
public:
    Kid(std::string _name, int _money) : name{_name}, money{_money} {};

    std::string get_name() const
    {
        return name;
    }

    int get_money() const
    {
        return money;
    }

    void buy_plush(PlushStore &store)
    {
        auto plush = store.buy(money);
        if (plush)
            money -= plush.value().get_cost();
    }

private:
    std::string name;
    int money;
};

std::ostream &operator<<(std::ostream &stream, const Kid &kid)
{
    return stream << kid.get_name() << " has " << kid.get_money() << " euros.";
}