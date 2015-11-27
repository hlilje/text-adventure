#include "environments.hpp"


using namespace text_adventure;

Environment::Environment() : neighbours(std::vector<Environment *>(4)) {};

std::string Environment::description() {
    return type();
}

std::vector<Direction> Environment::directions() {
    return std::vector<Direction>();
}

Environment * Environment::neighbour(const Direction dir) {
    return neighbours[0];
}

void Environment::enter(const Actor & character) {

}

void Environment::exit(const Actor & character) {

}

void Environment::pick_up(const Object & object) {

}

void Environment::drop(const Object & object) {

}
