#include "actors.hpp"

using namespace text_adventure;


Dragon::Dragon(Environment * const room, std::string const name)
    : Creature(room, "dragon", name), curr_dir(SOUTH) {}

void Dragon::action() {
    auto dirs = _room->directions();

    if(std::find(dirs.begin(), dirs.end(), curr_dir) != dirs.end()
    && _room->neighbour(curr_dir)->type() == "mountain") {
        go(curr_dir);
        return;
    }

    for(Direction d : dirs) {
        if(_room->neighbour(d)->type() == "mountain") {
            go(d);
            curr_dir = d;
            break;
        }
    }
}

void Dragon::fight(Actor * const character) {
}
