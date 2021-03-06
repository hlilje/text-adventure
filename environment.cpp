#include "environments.hpp"


using namespace text_adventure;

Environment::Environment() : _neighbours(std::vector<Environment *>(4)) {}

std::string Environment::description() const {
    std::string desc = "You are in a " + type() + ".\n\n";

    if (const Outdoor * const outdoor = dynamic_cast<const Outdoor *>(this))
        desc += "The weather is " + outdoor->weather() + ".\n\n";

    if(_objects.empty())
        desc += "The place contains no items.\n\n";
    else {
        desc += "You see the following items:\n";
        for(Object * const o : _objects)
            desc += "A " + o->type() + "\n";
        desc += "\n";
    }

    desc += "There are exits in the following directions:";
    for(size_t i = 0; i < _neighbours.size(); ++i)
        if(_neighbours[i] != nullptr) {
            if(i == 0)
                desc += " north";
            else if(i == 1)
                desc += " east";
            else if(i == 2)
                desc += " south";
            else
                desc += " west";
        }
    desc += "\n";

    return desc;
}

std::unordered_set<Actor *> const & Environment::monsters() const {
    return _actors;
}

std::unordered_set<Object *> const & Environment::objects() const {
    return _objects;
}

std::vector<Direction> Environment::directions() const {
    std::vector<Direction> dirs;
    for(size_t i = 0; i < _neighbours.size(); ++i)
        if(_neighbours[i] != nullptr)
            dirs.push_back((Direction) i);
    return dirs;
}

Environment * Environment::neighbour(const Direction dir) const {
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

