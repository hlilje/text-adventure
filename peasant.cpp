#include "actors.hpp"

using namespace text_adventure;


Peasant::Peasant(Environment * const room,
                 std::string const name)
    : Human(room, "peasant", name) {}

void Peasant::action() {
}

void Peasant::drop(const Object & object) {
}

void Peasant::fight(const Actor & character) {
};

void Peasant::pick_up(const Object & object) {
};
