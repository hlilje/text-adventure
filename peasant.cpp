#include "actors.hpp"

using namespace text_adventure;


Peasant::Peasant(Environment * const room,
                 std::string const name)
    : Human(50, 1, room, "peasant", name) {}

std::string Peasant::action() {
    return "";
}

std::string Peasant::fight(Actor * const character) {
    return "";
}
