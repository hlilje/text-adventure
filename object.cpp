#include "objects.hpp"

using namespace text_adventure;

Object::Object(int vol, int weight, bool liquid) 
    : _volume(vol), _weight(weight), _is_liquid(liquid) {}


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
