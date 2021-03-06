#include "actors.hpp"

using namespace text_adventure;


Wizard::Wizard(Environment * const room,
               std::string const & name)
    : Human(150, 5, room, "wizard", name), _mana(100) {}

std::string Wizard::action() {
    return "";
}

std::string Wizard::fight(Actor * const character) {
    if(_mana >= 30) {
        _mana -= 30;
        return "You cast Lightning Bolt on the " + character->type()
               + " " + character->name() + " for " +
               std::to_string(character->take_damage(150))
               + " damage.";
    }
    return "You slap the " + character->type() + " "
           + character->name() + " with your bare hands for " +
           std::to_string(character->take_damage(_attack_damage))
           + " damage.";
}

std::string Wizard::statistics() const {
    std::string stats = Human::statistics();
    stats += "You have " + std::to_string(_mana) + " mana points.\n";
    return stats;
}

bool Wizard::consume_object(Object * const object) {
    if (Potion * const potion = dynamic_cast<Potion *>(object)) {
        if(potion->type() == "mana_potion") {
            _mana += potion->mana();
        }
    }

    return Human::consume_object(object);
}

