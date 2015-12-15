#include "actors.hpp"

using namespace text_adventure;


Goblin::Goblin(Environment * const room, std::string const & name)
    : Humanoid(100, 20, room, "goblin", name) {}

std::string Goblin::action() {
    if(_health > 50) {
        Human * human = nullptr;
        for(Actor * actor : _room->monsters()) {
            if((human = dynamic_cast<Human *>(actor))) {
                return fight(actor);
            }
        }
    }

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
    return _name + " punches you for " +
           std::to_string(character->take_damage(_attack_damage)) + " damage.";
}
