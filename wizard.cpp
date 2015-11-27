#include "actors.hpp"

using namespace text_adventure;


Wizard::Wizard(Environment * const room,
               std::string const name)
    : Human(room, "wizard", name) {}

void Wizard::action() {
}

void Wizard::drop(const Object & object) {
}

void Wizard::fight(const Actor & character) {
};

void Wizard::pick_up(const Object & object) {
};
