#include "actors.hpp"

using namespace text_adventure;


Zombie::Zombie(Environment * const room, std::string const name)
    : Humanoid(room, "zombie", name) {}

void Zombie::action() {
    auto dirs = _room->directions();
    for(Direction d : dirs) {
        if(_room->neighbour(d)->type() == "cave")
            go(d);
    }
}

void Zombie::fight(Actor * const character) {
}
