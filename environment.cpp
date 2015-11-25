#include "environments.hpp"


using namespace text_adventure;


std::string Environment::description() {
    return type();
}

vector<Direction> Environment::directions() {
    return vector<Direction>();
}

Environment Environment::neighbour(const Direction dir) {
    return *this;
}

void Environment::enter(const Actor & character) {

}

void Environment::exit(const Actor & character) {

}

void Environment::pick_up(const Object & object) {

}

void Environment::drop(const Object & object) {

}
