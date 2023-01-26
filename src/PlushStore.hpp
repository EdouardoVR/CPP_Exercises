#pragma once
#include <string>

class PlushStore
{
public:
    PlushStore(std::string _name) : name{_name} {};

    std::string get_name() const
    {
        return name;
    }

    int get_wealth_amount() const
    {
        return wealth;
    }

    int get_stock_size() const
    {
        return stock;
    }

    void loan(int value)
    {
        wealth += value;
    }

    int get_debt_amount()
    {
        return wealth * 1.1;
    }

    int make_plush(int price)
    {
        if (wealth > 0)
        {

            wealth -= price;
            if (wealth < 0)
            {
                wealth = 0;
            }
            stock += 1;
        }
        return price + stock;
    }

    int get_experience() const
    {
        return stock;
    }

private:
    std::string name;
    int wealth = 0;
    int stock = 0;
};