#include "objects.hpp"

using namespace text_adventure;


Food::Food(std::string const type, int const vol, int const weight,
           int const health) :
    Consumable(type, vol, weight, false),
    _health(health) {}

int Food::health() const {
    return _health;
}
