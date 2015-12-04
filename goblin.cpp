#include "actors.hpp"

using namespace text_adventure;


Goblin::Goblin(Environment * const room, std::string const name)
    : Humanoid(room, "goblin", name) {}

void Goblin::action() {
}

void Goblin::fight(Actor * const character) {
}
