#include "actors.hpp"

using namespace text_adventure;


Human::Human(Environment * const room,
             std::string const type,
             std::string const name)
    : Actor(room, type, name), _hand(nullptr), _back(nullptr) {}

bool Human::drop(const std::string & item) {
    Object * object = _back != nullptr ? _back->find(item) : _hand;

    // Container on back
    if (_back != nullptr) {
        if (object == nullptr) {
            if (_hand == nullptr) {
                return false;
            } else {
                if (_hand->type() != item)
                    return false;
                else
                    _hand = nullptr;
            }
        } else {
            _back->remove(object);
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

    _room->drop(object);

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

    _room->pick_up(*it);

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

std::string Human::items() {
    if(_hand == nullptr && _back == nullptr)
        return "You aren't carrying any items.\n";

    std::string inv;
    if(_hand != nullptr) {
        inv += "You are holding a " + _hand->type()
            + " (" + std::to_string(_hand->weight())
            + "kg, " + std::to_string(_hand->volume())
            + "l) in your hand.\n";

        if(_back != nullptr) inv += "\n";
    }

    if(_back != nullptr) {
        inv += "You are carrying a " + _back->type()
            + " (" + std::to_string(_back->weight())
            + "kg, " + std::to_string(_back->volume())
            + "l) on your back.\n"
            + "It has a capacity of "
            + std::to_string(_back->max_volume()) + "l and "
            + std::to_string(_back->max_weight()) + "kg.\n";

        auto contents = _back->contents();
        if(contents.empty())
            inv += "It contains no items.\n";
        else {
            inv += "It contains the following items:\n";
            for(auto it : contents)
                inv += "A " + it->type()
                    + " (" + std::to_string(it->weight())
                    + "kg, " + std::to_string(it->volume()) + "l)\n";
        }
    }

    return inv;
}

void Human::go(const Direction direction) {
    _room = _room->neighbour(direction);
}

void Human::action() {
}
