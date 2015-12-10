#include "actors.hpp"

using namespace text_adventure;


Warrior::Warrior(Environment * const room,
                 std::string const name)
    : Human(300, 10, room, "warrior", name) {}

std::string Warrior::action() {
    return "";
}

std::string Warrior::fight(Actor * const character) {
    return "";
}
