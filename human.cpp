#include "actors.hpp"

using namespace text_adventure;


Human::Human(Environment * room) : Actor(room) {
}

void Human::go(const Direction direction) {
    Environment * new_room = _room->neighbour(direction);
    _room = new_room;
}

void Human::action() {
}

void Human::drop(const Object & object) {
}

void Human::fight(const Actor & character) {
};

void Human::pick_up(const Object & object) {
};

std::string Human::look() {
    std::string sight = _room->description() + "\n";

    auto monsters = _room->monsters();

    if(monsters.empty())
        sight += "There is noone else here.\n\n";
    else {
        sight += "There are the following monsters here:\n";
        for(Actor * const m : monsters)
            sight += "A " + m->type() + " named " + m->name() + "\n";
        sight += "\n";
    }
    return sight;
}
