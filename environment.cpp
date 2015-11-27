#include "environments.hpp"


using namespace text_adventure;

Environment::Environment() : _neighbours(std::vector<Environment *>(4)) {}

std::string Environment::description() {
    std::string desc = "You are in a " + type() + ".\n\n";

    if(_actors.empty())
        desc += "The place contains no items.\n\n";
    else {
        desc += "You see the following items:\n";
        for(Object * const o : _objects)
            desc += "A " + o->type() + "\n";
        desc += "\n";
    }

    desc += "There are exits in the following directions: ";
    for(size_t i = 0; i < _neighbours.size(); ++i)
        if(_neighbours[i] != nullptr)
            desc += ((Direction) i) + " ";
    desc += "\n";

    return desc;
}

std::unordered_set<Actor *> const & Environment::monsters() {
    return _actors;
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

void Environment::enter(Actor * const character) {
    _actors.insert(character);
}

void Environment::exit(Actor * const character) {
    _actors.erase(character);
}

void Environment::pick_up(Object * const object) {
    _objects.erase(object);
}

void Environment::drop(Object * const object) {
    _objects.insert(object);
}

void Environment::add_neighbour(Direction dir, Environment * const room) {
    _neighbours[dir] = room;
}

