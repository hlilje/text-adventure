#include "actors.hpp"

using namespace text_adventure;


Zombie::Zombie(Environment * const room, std::string const name)
    : Humanoid(50, 10, room, "zombie", name) {}

std::string Zombie::action() {
    Human * human = nullptr;
    for(Actor * actor : _room->monsters()) {
        if((human = dynamic_cast<Human *>(actor))) {
            return fight(actor);
        }
    }

    int i = rand() % 100;
    if(i > 50) return "";

    auto dirs = _room->directions();
    i = rand() % dirs.size();
    Direction d = dirs[i];
    while(_room->neighbour(d)->type() != "cave") {
        i = rand() % dirs.size();
        d = dirs[i];
    }
    go(d);
    return "";
}

std::string Zombie::fight(Actor * const character) {
    int dmg = 10;
    character->take_damage(dmg);
    return _name + " hits you for " + std::to_string(dmg) + " damage.";
}
