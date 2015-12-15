#include "actors.hpp"
#include "environments.hpp"

using namespace text_adventure;


Castle::Castle(const bool locked) : Indoor(locked) {

}

std::string Castle::type() {
    return "castle";
}
