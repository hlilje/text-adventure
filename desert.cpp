#include "actors.hpp"
#include "environments.hpp"

using namespace text_adventure;


Desert::Desert() : Outdoor() {

}

std::string Desert::type() {
    return "desert";
}
