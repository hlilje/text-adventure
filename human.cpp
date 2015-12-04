#include "actors.hpp"

using namespace text_adventure;


Human::Human(Environment * const room,
             std::string const type,
             std::string const name)
    : Actor(room, type, name), _hand(nullptr), _back(nullptr) {}

bool Human::drop(const std::string & item) {
    // Container on back
    if (_back != nullptr) {
        if (!_back->contains(item)) {
            if (_hand == nullptr) {
                return false;
            } else {
                if (_hand->type() != item)
                    return false;
                else
                    _hand = nullptr;
            }
        } else {
            _back->remove(item);
        }
    // Nothing on back
    } else {
        if (_hand == nullptr) {
            return false;
        } else {
            if (_hand->type() != item)
                return false;
            else
                _hand = nullptr;
        }
    }

    return true;
}

void Human::fight(const std::string & character) {
};

bool Human::pick_up(const std::string & item) {
    // Find the object in the current room
    auto & objects = _room->objects();
    auto finder = [item](Object * const other) {
        return other->type() == item;
    };
    auto it = std::find_if(objects.begin(), objects.end(), finder);

    if (it == objects.end())
        return false;

    Object * const object = *it;

    // Container on back
    if (_back != nullptr) {
        if (!_back->add(object)) {
            if (_hand != nullptr)
                return false;
            else
                _hand = object;
        }
    // Nothing on back
    } else {
        if (object->type() == "knapsack") {
            if (_back != nullptr) {
                return false;
            } else {
                Knapsack * const knapsack = dynamic_cast<Knapsack *>(object);
                _back = knapsack;
            }
        } else {
            if (_hand != nullptr)
                return false;
            else
                _hand = object;
        }
    }

    objects.erase(*it);

    return true;
};

std::string Human::look() {
    std::string sight = _room->description() + "\n";

    auto monsters = _room->monsters();

    if(monsters.empty())
        sight += "There is noone else here.\n";
    else {
        sight += "There are the following monsters here:\n";
        for(Actor * const m : monsters)
            sight += "A " + m->type() + " named " + m->name() + "\n";
    }
    return sight;
}

void Human::go(const Direction direction) {
    _room = _room->neighbour(direction);
}

void Human::action() {
}
