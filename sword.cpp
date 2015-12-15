#include "objects.hpp"

using namespace text_adventure;


Sword::Sword(std::string const & type, int const vol,
             int const weight, int const damage) :
    Weapon(type, vol, weight, damage) {}
