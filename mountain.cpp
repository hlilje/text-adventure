#include "actors.hpp"
#include "environments.hpp"

using namespace text_adventure;


Mountain::Mountain() : Outdoor() {

}

std::string Mountain::type() const {
    return "mountain";
}
