#include "actors.hpp"

using namespace text_adventure;


Worg::Worg(Environment * const room, std::string const name)
    : Creature(room, "worg", name) {}

void Worg::action() {
    auto dirs = _room->directions();
    int i = rand() % dirs.size();
    Direction d = dirs[i];
    while(_room->neighbour(d)->type() != "desert") {
        i = rand() % dirs.size();
        d = dirs[i];
    }
    go(d);
}

void Worg::fight(Actor * const character) {
}
