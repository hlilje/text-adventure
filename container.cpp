#include "objects.hpp"

using namespace text_adventure;


Container::Container(std::string const type, int const vol,
                     int const weight, bool const liquid,
                     const int max_volume, const int max_weight,
                     const bool holds_liquid) :
    Object(type, vol, weight, liquid),
    _holds_liquid(holds_liquid), _max_volume(max_volume),
    _max_weight(max_weight) {}

bool Container::add(Object * const object) {
    int volume = 0, weight = 0;

    for (const auto & object : _objects) {
        volume += object->volume();
        weight += object->weight();
    }

    if (volume + object->volume() > _max_volume ||
        weight + object->weight() > _max_weight)
        return false;

    _objects.insert(object);

    return true;
}

int Container::max_volume() const {
    return _max_volume;
}

int Container::max_weight() const {
    return _max_weight;
}

bool Container::contains(const std::string & item) const {
    auto finder = [item](Object * const other) {
        return other->type() == item;
    };
    auto it = std::find_if(_objects.begin(), _objects.end(), finder);
    return it == _objects.end();
}

void Container::remove(const std::string & item) {
    auto finder = [item](Object * const other) {
        return other->type() == item;
    };
    auto it = std::find_if(_objects.begin(), _objects.end(), finder);
    if (it != _objects.end()) _objects.erase(it);
}
