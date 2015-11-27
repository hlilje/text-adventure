#include "actors.hpp"

using namespace text_adventure;


Human::Human(Environment * room) : Actor(room) {
}

void Human::go(const Direction direction) {
}

void Human::action() {
}

void Human::drop(const Object & object) {
}

void Human::fight(const Actor & character) {
};

void Human::pick_up(const Object & object) {
};
