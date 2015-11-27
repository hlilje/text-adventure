#include "actors.hpp"

using namespace text_adventure;


Warrior::Warrior(Environment * const room,
                 std::string const name)
    : Human(room, "warrior", name) {}

void Warrior::action() {
}

void Warrior::drop(const Object & object) {
}

void Warrior::fight(const Actor & character) {
};

void Warrior::pick_up(const Object & object) {
};
