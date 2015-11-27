#include "actors.hpp"

using namespace text_adventure;


Wizard::Wizard(Environment * const room,
               std::string const name)
    : Human(room, "wizard", name) {}

void Wizard::action() {
}

void Wizard::fight(Actor * const character) {
};
