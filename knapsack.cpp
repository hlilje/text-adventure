#include "objects.hpp"

using namespace text_adventure;


Knapsack::Knapsack(const int max_volume, const int max_weight) :
    Container("knapsack", 10, 2, false, max_volume, max_weight, false) {}
