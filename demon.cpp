#include "actors.hpp"

using namespace text_adventure;


Demon::Demon(Environment * const room, std::string const name)
    : Humanoid(200, 30, room, "demon", name) {}

std::string Demon::action() {
    Human * human = nullptr;
    for(Actor * actor : _room->monsters()) {
        if((human = dynamic_cast<Human *>(actor))) {
            return fight(actor);
        }
    }
    return "";
}

std::string Demon::fight(Actor * const character) {
    return _name + " slashes you for " +
           std::to_string(character->take_damage(_attack_damage)) + " damage.";
}
