#include "environments.hpp"


using namespace text_adventure;

Environment::Environment() : _neighbours(std::vector<Environment *>(4)) {};

std::string Environment::description() {
    return type();
}

std::vector<Direction> Environment::directions() {
    std::vector<Direction> dirs;
    for(size_t i = 0; i < _neighbours.size(); ++i)
        if(_neighbours[i] != nullptr)
            dirs.push_back((Direction) i);
    return dirs;
}

Environment * Environment::neighbour(const Direction dir) {
    return _neighbours[dir];
}

void Environment::enter(const Actor * character) {
    _actors.insert(character);
}

void Environment::exit(const Actor * character) {
    _actors.erase(character);
}

void Environment::pick_up(const Object * object) {
    _objects.erase(object);
}

void Environment::drop(const Object * object) {
    _objects.insert(object);
}
