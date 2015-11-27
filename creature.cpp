#include "actors.hpp"

using namespace text_adventure;


Creature::Creature(Environment * const room,
                   std::string const type,
                   std::string const name)
    : Actor(room, type, name) {}

void Creature::action() {
}

void Creature::drop(const Object & object) {
}

void Creature::fight(const Actor & character) {
};

void Creature::pick_up(const Object & object) {
};
