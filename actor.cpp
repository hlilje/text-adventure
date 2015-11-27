#include "actors.hpp"

using namespace text_adventure;

Actor::Actor(Environment * const room,
             std::string const type,
             std::string const name)
    : _room(room), _type(type), _name(name) {}

std::string Actor::name() {
    return _name;
}

std::string Actor::type() {
    return _type;
}

Environment * Actor::get_room() {
    return _room;
}

void Actor::go(const Direction direction) {
    Environment * new_room = _room->neighbour(direction);
    _room->exit(this);
    new_room->enter(this);
    _room = new_room;
}
