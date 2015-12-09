#include "objects.hpp"

using namespace text_adventure;


Potion::Potion(std::string const type, int const vol, int const weight,
               int const health, int const mana) :
    Consumable(type, vol, weight, true),
    _health(health), _mana(mana) {}

int Potion::health() const {
    return _health;
}

int Potion::mana() const {
    return _mana;
}
