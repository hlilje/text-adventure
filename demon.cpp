#include "actors.hpp"

using namespace text_adventure;


Demon::Demon(Environment * const room, std::string const name)
    : Humanoid(room, "demon", name) {}

void Demon::action() {
}

void Demon::fight(Actor * const character) {
}
