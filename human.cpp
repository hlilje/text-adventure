#include "actors.hpp"

using namespace text_adventure;


Human::Human(int const health, int const attack_damage,
             Environment * const room,
             std::string const & type,
             std::string const & name)
    : Actor(health, attack_damage, room, type, name),
      _hand(nullptr), _back(nullptr) {}

bool Human::consume_object(Object * const object) {
    if (Food * const food = dynamic_cast<Food *>(object)) {
        _health += food->health();
        return true;
    // Virtual Wizard function increases mana
    } else if (Potion * const potion = dynamic_cast<Potion *>(object)) {
        if (potion->type() == "elixir_of_invincibility") {
            _invincible = true;
            _invincibility_timer = 5;
        } else {
            _health += potion->health();
        }
        return true;
    }
    return false;
}

bool Human::consume(const std::string & consumable) {
    Object * object = _back != nullptr ? _back->find(consumable) : nullptr;

    // On back
    if (object != nullptr) {
        if(!consume_object(object))
            return false;
        _back->remove(object);
    // Maybe in hand
    } else if (_hand != nullptr && _hand->type() == consumable) {
        object = _hand;
        if(!consume_object(object))
            return false;
        _hand = nullptr;
    } else {
        return false;
    }

    return true;
}

bool Human::drop(const std::string & item) {
    if (item == "knapsack") {
        if (_back == nullptr)
            return false;
        if (_back->type() != "knapsack")
            return false;
        _room->drop(_back);
        _back = nullptr;
        return true;
    }

    if (_hand != nullptr && _hand->type() == item) {
        _room->drop(_hand);
        _hand = nullptr;
        return true;
    }

    if (_back == nullptr)
        return false;

    Object * object = _back->find(item);

    if (object == nullptr)
        return false;

    if (!_back->remove(object))
            return false;

    _room->drop(object);

    return true;
}

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

    if (object->type() == "knapsack") {
        if (_back != nullptr) {
            return false;
        } else {
            Knapsack * const knapsack = dynamic_cast<Knapsack *>(object);
            _back = knapsack;
        }
    } else {
        // Prefer to put in hand
        if (_hand == nullptr) {
            _hand = object;
        // Try to put on back
        } else {
            if (_back == nullptr)
                return false;

            if (!_back->add(object))
                return false;
        }
    }

    _room->pick_up(object);

    return true;
}

std::string Human::look() const {
    std::string sight = _room->description() + "\n";

    const auto monsters = _room->monsters();

    if(monsters.empty() || (monsters.size() == 1 &&
       monsters.count(const_cast<Human *>(this)) > 0))
        sight += "There is noone else here.\n";
    else {
        sight += "There are the following monsters here:\n";
        for(Actor * const m : monsters)
            if(m != this) {
                if(m->is_dead())
                    sight += "The corpse of a ";
                else
                    sight += "A ";
                sight += m->type() + " named " + m->name() + "\n";
            }
    }
    return sight;
}

std::string Human::items() const {
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

std::string Human::statistics() const {
    std::string stats = "You are a " + _type + " named " + _name + ".\n";
    stats += "You do " + std::to_string(_attack_damage) + " damage without a weapon.\n";
    stats += "You currently have " + std::to_string(_health) + " health points.\n";
    if(_invincible) stats += "You cannot be harmed!\n";
    return stats;
}

bool Human::has_item(std::string const & item) const {
    if (_hand == nullptr && _back == nullptr)
        return false;

    if (_hand != nullptr && _back == nullptr) {
        if (_hand->type() != item)
            return false;
    }

    if (_hand == nullptr && _back != nullptr) {
        if (!_back->find(item))
            return false;
    }

    if (_hand != nullptr && _back != nullptr) {
        if (_hand->type() != item) {
            if (!_back->find(item))
                return false;
        }
    }

    return true;
}
