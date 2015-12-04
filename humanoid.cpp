#include "actors.hpp"

using namespace text_adventure;


Humanoid::Humanoid(Environment * const room,
                   std::string const type,
                   std::string const name)
    : Actor(room, type, name) {}

void Humanoid::action() {
}

void Humanoid::fight(Actor * const character) {
};
