#include "ex1.hpp"

void pairwise_concatenate(std::list<std::list<int>>& l1, std::list<std::list<int>>& l2)
{
    for (unsigned i = l1.size(); i < l2.size(); ++i)
        l1.emplace_back();
    auto it1 = l1.begin();
    for (auto it2 = l2.begin(); it2 != l2.end(); ++it2)
    {
        concatenate(*it1, *it2);
        ++it1;
    }
}

void pairwise_concatenate(std::list<std::list<int>>& l1, std::list<std::list<int>>&& l2)
{
    for (unsigned i = l1.size(); i < l2.size(); ++i)
        l1.emplace_back();
    auto it1 = l1.begin();
    for (auto it2 = l2.begin(); it2 != l2.end(); ++it2)
    {
        concatenate(*it1, std::move(*it2));
        ++it1;
    }
}