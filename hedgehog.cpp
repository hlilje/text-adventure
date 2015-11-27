#include "actors.hpp"

using namespace text_adventure;


Hedgehog::Hedgehog(Environment * const room, std::string const name)
    : Creature(room, "hedgehog", name) {}

void Hedgehog::action() {
}

void Hedgehog::fight(Actor * const character) {
};
