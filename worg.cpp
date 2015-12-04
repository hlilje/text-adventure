#include "actors.hpp"

using namespace text_adventure;


Worg::Worg(Environment * const room, std::string const name)
    : Creature(room, "worg", name) {}

void Worg::action() {
}

void Worg::fight(Actor * const character) {
}
