#include "actors.hpp"

using namespace text_adventure;


Dragon::Dragon(Environment * const room, std::string const name)
    : Creature(room, "hedgehog", name) {}

void Dragon::action() {
}

void Dragon::fight(Actor * const character) {
}
