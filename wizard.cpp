#include "actors.hpp"

using namespace text_adventure;


Wizard::Wizard(Environment * const room,
               std::string const name)
    : Human(150, 5, room, "wizard", name), _mana(100) {}

void Wizard::action() {
}

void Wizard::fight(Actor * const character) {
};

std::string Wizard::statistics() const {
    std::string stats = Human::statistics();
    stats += "You have " + std::to_string(_mana) + " mana points.\n";
    return stats;
}

bool Wizard::consume(const std::string & consumable) {
    // TODO: More logic
    Object * object = _back != nullptr ? _back->find(consumable) : _hand;

    if (object == nullptr) return false;

    if (Potion * const potion = dynamic_cast<Potion *>(object)) {
        if (potion->type() == "mana_potion") {
            _mana += potion->mana();
        }
    }

    // Updates additional stats and removes from inventory
    return Human::consume(consumable);
}
