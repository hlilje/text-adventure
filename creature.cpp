#include "actors.hpp"

using namespace text_adventure;


Creature::Creature(Environment * const room,
                   std::string const type,
                   std::string const name)
    : Actor(room, type, name) {}

void Creature::action() {
}

void Creature::fight(Actor * const character) {
};
