#include "actors.hpp"

using namespace text_adventure;


Actor::Actor() {
}

std::string Actor::name() {
    return _name;
}
std::string Actor::type() {
    return _type;
}

void Actor::go(const Direction direction) {
}
