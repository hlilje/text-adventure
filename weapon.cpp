#include "objects.hpp"

using namespace text_adventure;


Weapon::Weapon(std::string const type, int const vol,
               int const weight, int const damage) :
    Object(type, vol, weight, false),  _damage(damage) {}

int Weapon::damage() const {
    return _damage;
}
