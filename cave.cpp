#include "actors.hpp"
#include "environments.hpp"

using namespace text_adventure;


Cave::Cave(const bool locked) : Indoor(locked) {

}

std::string Cave::type() {
    return "cave";
}
