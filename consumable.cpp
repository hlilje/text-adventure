#include "objects.hpp"

using namespace text_adventure;


Consumable::Consumable(std::string const type, int const vol,
                       int const weight, bool const liquid) :
    Object(type, vol, weight, liquid) {}
