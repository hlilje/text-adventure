#include "actors.hpp"

using namespace text_adventure;


Zombie::Zombie(Environment * const room, std::string const name)
    : Humanoid(room, "zombie", name) {}

void Zombie::action() {
}

void Zombie::fight(Actor * const character) {
}
