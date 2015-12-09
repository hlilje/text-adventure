#include "objects.hpp"

using namespace text_adventure;


Bottle::Bottle(const int max_volume, const int max_weight) :
    Container("bottle", 4, 2, false, max_volume, max_weight, true) {}
