#include "actors.hpp"

using namespace text_adventure;


Hedgehog::Hedgehog(Environment * const room, std::string const & name)
    : Creature(10, 1, room, "hedgehog", name) {}

std::string Hedgehog::action() {
    auto dirs = _room->directions();
    for(Direction d : dirs) {
        if(_room->neighbour(d)->type() == "forest") {
            go(d);
            break;
        }
    }
    return "";
}

std::string Hedgehog::fight(Actor * const character) {
    return "";
}
