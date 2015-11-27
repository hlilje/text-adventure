#include "actors.hpp"

using namespace text_adventure;


Creature::Creature(Environment * room) : Actor(room) {
}

void Creature::go(const Direction direction) {
}

void Creature::action() {
}

void Creature::drop(const Object & object) {
}

void Creature::fight(const Actor & character) {
};

void Creature::pick_up(const Object & object) {
};
