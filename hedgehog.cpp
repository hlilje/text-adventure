#include "actors.hpp"

using namespace text_adventure;


Hedgehog::Hedgehog(Environment * const room, std::string const name)
    : Creature(room, "hedgehog", name) {}

void Hedgehog::action() {
}

void Hedgehog::drop(const Object & object) {
}

void Hedgehog::fight(const Actor & character) {
};

void Hedgehog::pick_up(const Object & object) {
};
