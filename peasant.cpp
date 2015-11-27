#include "actors.hpp"

using namespace text_adventure;


Peasant::Peasant(Environment * const room,
                 std::string const name)
    : Human(room, "peasant", name) {}

void Peasant::action() {
}

void Peasant::fight(Actor * const character) {
};
