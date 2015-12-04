#include "actors.hpp"

using namespace text_adventure;


Zombie::Zombie(Environment * const room, std::string const name)
    : Humanoid(room, "zombie", name) {}

void Zombie::action() {
    auto dirs = _room->directions();
    int i = rand() % dirs.size();
    Direction d = dirs[i];
    while(_room->neighbour(d)->type() != "cave") {
        i = rand() % dirs.size();
        d = dirs[i];
    }
    go(d);
}

void Zombie::fight(Actor * const character) {
}
