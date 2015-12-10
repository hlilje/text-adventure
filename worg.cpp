#include "actors.hpp"

using namespace text_adventure;


Worg::Worg(Environment * const room, std::string const name)
    : Creature(100, 20, room, "worg", name) {}

std::string Worg::action() {
    Human * human = nullptr;
    for(Actor * actor : _room->monsters()) {
        if((human = dynamic_cast<Human *>(actor))) {
            return fight(actor);
        }
    }

    if(Outdoor * env = dynamic_cast<Outdoor *>(_room)) {
        if(env->weather() == "windy") {
            int i = rand() % 100;
            if(i > 50)
                return "";
        }
    }

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
    return _name + " bites you for " +
           std::to_string(character->take_damage(_attack_damage)) + " damage.";
}
