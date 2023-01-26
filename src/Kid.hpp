#pragma once
#include <string>
#include <iostream>

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

private:
    std::string name;
    int money;
};

std::ostream &operator<<(std::ostream &stream, const Kid &kid)
{
    return stream << kid.get_name() << " has " << kid.get_money() << " euros.";
}