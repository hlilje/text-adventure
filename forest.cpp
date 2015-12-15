#include "actors.hpp"
#include "environments.hpp"

using namespace text_adventure;


Forest::Forest() : Outdoor() {

}

std::string Forest::type() const {
    return "forest";
}
