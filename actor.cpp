#include "actors.hpp"

using namespace text_adventure;

Actor::Actor(int const health,
             int const attack_damage,
             Environment * const room,
             std::string const type,
             std::string const name)
    : _health(health), _attack_damage(attack_damage), _invincibility_timer(0),
      _invincible(false), _room(room), _type(type), _name(name) {}

std::string Actor::name() const {
    return _name;
}

std::string Actor::type() const {
    return _type;
}

Environment * Actor::get_room() const {
    return _room;
}

void Actor::update() {
    if (_invincibility_timer > 0) {
        --_invincibility_timer;
    } else {
        _invincibility_timer = 0;
        _invincible = false;
    }
}

void Actor::go(const Direction direction) {
    Environment * new_room = _room->neighbour(direction);
    _room->exit(this);
    new_room->enter(this);
    _room = new_room;
}

int Actor::take_damage(int dmg) {
    if(_health > 0 && !_invincible) {
        _health -= dmg;
        return dmg;
    }
    return 0;
}

bool Actor::is_dead() const {
    return _health <= 0;
}
