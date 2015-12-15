#include "actors.hpp"
#include "environments.hpp"

using namespace text_adventure;


Hut::Hut(const bool locked) : Indoor(locked) {

}

std::string Hut::type() {
    return "hut";
}
