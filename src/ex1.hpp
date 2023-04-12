#pragma once
#include "../lib/concatenate.hpp"

#include <list>

void pairwise_concatenate(std::list<std::list<int>>& l1, std::list<std::list<int>>& l2);

void pairwise_concatenate(std::list<std::list<int>>& l1, std::list<std::list<int>>&& l2);