#include "actors.hpp"

using namespace text_adventure;


Worg::Worg(Environment * const room, std::string const name)
    : Creature(100, 20, room, "worg", name) {}

std::string Worg::action() {
    auto dirs = _room->directions();
    int i = rand() % dirs.size();
    Direction d = dirs[i];
    while(_room->neighbour(d)->type() != "desert") {
        i = rand() % dirs.size();
        d = dirs[i];
    }
    go(d);
    return "";
}

std::string Worg::fight(Actor * const character) {
    return "";
}
