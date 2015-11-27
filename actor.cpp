#include "actors.hpp"

using namespace text_adventure;

Actor::Actor(Environment * room) : _room(room) {}

std::string Actor::name() {
    return _name;
}

std::string Actor::type() {
    return _type;
}

void Actor::go(const Direction direction) {
    Environment * new_room = _room->neighbour(direction);
    _room->exit(this);
    new_room->enter(this);
    _room = new_room;
}
