#include "objects.hpp"

using namespace text_adventure;

Object::Object(std::string const type, int const vol,
               int const weight, bool const liquid) 
    : _type(type), _volume(vol), _weight(weight), _is_liquid(liquid) {}


bool Object::is_liquid() {
    return _is_liquid;
}

int Object::volume() {
    return _volume;
}

int Object::weight() {
    return _weight;
}

std::string Object::type() {
    return _type;
}
