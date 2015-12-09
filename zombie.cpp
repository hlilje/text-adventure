#include "actors.hpp"

using namespace text_adventure;


Zombie::Zombie(Environment * const room, std::string const name)
    : Humanoid(50, 10, room, "zombie", name) {}

void Zombie::action() {
    int i = rand() % 100;
    if(i > 50) return;

    auto dirs = _room->directions();
    i = rand() % dirs.size();
    Direction d = dirs[i];
    while(_room->neighbour(d)->type() != "cave") {
        i = rand() % dirs.size();
        d = dirs[i];
    }
    go(d);
}

void Zombie::fight(Actor * const character) {
}
