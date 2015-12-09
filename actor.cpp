#include "actors.hpp"

using namespace text_adventure;

Actor::Actor(int const health,
             int const attack_damage,
             Environment * const room,
             std::string const type,
             std::string const name)
    : _health(health), _attack_damage(attack_damage), _invincible(false),
      _room(room), _type(type), _name(name) {}

std::string Actor::name() const {
    return _name;
}

std::string Actor::type() const {
    return _type;
}

Environment * Actor::get_room() const {
    return _room;
}

void Actor::go(const Direction direction) {
    Environment * new_room = _room->neighbour(direction);
    _room->exit(this);
    new_room->enter(this);
    _room = new_room;
}
