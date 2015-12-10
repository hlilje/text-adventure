#include "actors.hpp"

using namespace text_adventure;


Goblin::Goblin(Environment * const room, std::string const name)
    : Humanoid(100, 20, room, "goblin", name) {}

std::string Goblin::action() {
    auto dirs = _room->directions();
    for(Direction d : dirs) {
        auto next_room = _room->neighbour(d);
        if(next_room->type() == "desert") {
            bool all_desert = true;
            for(Direction d : next_room->directions()) {
                if(next_room->neighbour(d)->type() != "desert")
                    all_desert = false;
            }
            if(!all_desert) {
                go(d);
                break;
            }
        }
    }
    return "";
}

std::string Goblin::fight(Actor * const character) {
    return "";
}
