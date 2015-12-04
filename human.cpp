#include "actors.hpp"

using namespace text_adventure;


Human::Human(Environment * const room,
             std::string const type,
             std::string const name)
    : Actor(room, type, name), _hand(nullptr) {}

void Human::go(const Direction direction) {
    _room = _room->neighbour(direction);
}

void Human::action() {
}

void Human::drop(const Object * const object) {
}

void Human::fight(Actor * const character) {
};

bool Human::pick_up(const Object * const object) {
    if (_hand != nullptr) return false;

    _hand = object;

    return true;
};

std::string Human::look() {
    std::string sight = _room->description() + "\n";

    auto monsters = _room->monsters();

    if(monsters.empty())
        sight += "There is noone else here.\n";
    else {
        sight += "There are the following monsters here:\n";
        for(Actor * const m : monsters)
            sight += "A " + m->type() + " named " + m->name() + "\n";
    }
    return sight;
}
