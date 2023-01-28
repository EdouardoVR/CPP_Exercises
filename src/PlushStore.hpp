#pragma once
#include <string>
#include <Plush.hpp>
#include <iostream>
#include <optional>
#include <vector>
#include <algorithm>

class PlushStore
{
private:
    std::string _name;
    int _wealth = 0;
    int _stock = 0;
    int _debt = 0;
    int _exp = 0;
    std::vector<int> _plushes;

public:
    PlushStore(std::string name) : _name{name} {};

    std::string get_name() const
    {
        return _name;
    }

    int get_wealth_amount() const
    {
        return _wealth;
    }

    int get_stock_size() const
    {
        return _stock;
    }

    void loan(int amount)
    {
        _wealth += amount;
        _debt += (int)amount * 1.1;
    }

    int get_debt_amount() const
    {
        return _debt;
    }

    int make_plush(int price)
    {
        if (_wealth > 0)
        {
            _wealth -= price;
            if (_wealth < 0)
                _wealth = 0;
            _stock++;
            int value = price + _exp++;
            _plushes.push_back(value);
            return value;
        }
        return 0;
    }

    int get_experience() const
    {
        return _exp;
    }

    std::optional<Plush> buy(int money)
    {
        const auto cheapest = std::min_element(_plushes.begin(), _plushes.end());
        const int price = *cheapest;
        if (money > price)
        {
            _wealth += price;
            _stock--;
            _plushes.erase(cheapest);
            return Plush{price};
        }
        return {};
    }
};

/*
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

    int get_debt_amount() const
    {
        return debt;
    }

    void loan(int amount)
    {
        wealth += amount;
        debt += (int)amount * 1.1;
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
                wealth = 0;
            int value = price + stock++;
            _plushes.push_back(value);
            return value;
        }
        return 0;
    }

    int get_experience() const
    {
        return stock;
    }

    std::optional<Plush> buy(int amount)
    {
        const auto cheapest = std::min_element(_plushes.begin(), _plushes.end());
        const int price = *cheapest;
        if (amount > price)
        {
            wealth -= amount;
            return Plush{amount};
            wealth += price;
            stock--;
            _plushes.erase(cheapest);
            return Plush{price};
        }
        return {};
    }

private:
    std::string name;
    int wealth = 0;
    int stock = 0;
    int debt = 0;
    std::vector<int> _plushes;
};*/