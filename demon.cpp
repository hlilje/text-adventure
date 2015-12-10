#include "actors.hpp"

using namespace text_adventure;


Demon::Demon(Environment * const room, std::string const name)
    : Humanoid(200, 30, room, "demon", name) {}

std::string Demon::action() {
    return "";
}

std::string Demon::fight(Actor * const character) {
    return "";
}
