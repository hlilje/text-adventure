#include "actors.hpp"

using namespace text_adventure;


Warrior::Warrior(Environment * const room,
                 std::string const name)
    : Human(room, "warrior", name) {}

void Warrior::action() {
}

void Warrior::fight(Actor * const character) {
};
