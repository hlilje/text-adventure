#include "actors.hpp"

using namespace text_adventure;


Dragon::Dragon(Environment * const room, std::string const name)
    : Creature(1000, 100, room, "dragon", name), curr_dir(SOUTH) {}

std::string Dragon::action() {
    Human * human = nullptr;
    for(Actor * actor : _room->monsters()) {
        if((human = dynamic_cast<Human *>(actor))) {
            return fight(actor);
        }
    }

    auto dirs = _room->directions();

    if(std::find(dirs.begin(), dirs.end(), curr_dir) != dirs.end()
    && _room->neighbour(curr_dir)->type() == "mountain") {
        go(curr_dir);
        return "";
    }

    for(Direction d : dirs) {
        if(_room->neighbour(d)->type() == "mountain") {
            go(d);
            curr_dir = d;
            break;
        }
    }
    return "";
}

std::string Dragon::fight(Actor * const character) {
    int dmg = _attack_damage;
    if(Outdoor * env = dynamic_cast<Outdoor *>(_room)) {
        if(env->weather() == "rainy")
            dmg /= 2;
    }
    return _name + " breathes fire on you for " +
           std::to_string(character->take_damage(dmg)) + " damage.";
}
