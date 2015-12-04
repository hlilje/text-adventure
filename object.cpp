#include "objects.hpp"

using namespace text_adventure;

Object::Object(std::string const type, int const vol,
               int const weight, bool const liquid) 
    : _type(type), _volume(vol), _weight(weight), _is_liquid(liquid) {}


bool Object::is_liquid() const {
    return _is_liquid;
}

int Object::volume() const {
    return _volume;
}

int Object::weight() const {
    return _weight;
}

std::string Object::type() const {
    return _type;
}
