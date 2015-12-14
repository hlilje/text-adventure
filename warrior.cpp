#include "actors.hpp"

using namespace text_adventure;


Warrior::Warrior(Environment * const room,
                 std::string const name)
    : Human(300, 10, room, "warrior", name) {}

std::string Warrior::action() {
    return "";
}

std::string Warrior::fight(Actor * const character) {
    Weapon * wep = nullptr;
    if(!(wep = dynamic_cast<Weapon *>(_hand)))
        return "You hit the " + character->type()
               + " " + character->name() + " with your fists for " +
               std::to_string(character->take_damage(_attack_damage))
               + " damage.";
    return "You hit the " + character->type()
           + " " + character->name() + " with your "
           + wep->type() + " for " +
           std::to_string(character->take_damage(wep->damage()))
           + " damage.";
}
