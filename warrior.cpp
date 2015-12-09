#include "actors.hpp"

using namespace text_adventure;


Warrior::Warrior(Environment * const room,
                 std::string const name)
    : Human(300, 10, room, "warrior", name) {}

void Warrior::action() {
}

void Warrior::fight(Actor * const character) {
};
