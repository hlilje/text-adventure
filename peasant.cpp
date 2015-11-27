#include "actors.hpp"

using namespace text_adventure;


Peasant::Peasant(Environment * room) : Human(room) {
}

void Peasant::action() {
}

void Peasant::drop(const Object & object) {
}

void Peasant::fight(const Actor & character) {
};

void Peasant::pick_up(const Object & object) {
};
