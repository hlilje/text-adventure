#include "actors.hpp"
#include "environments.hpp"

using namespace text_adventure;


Hut::Hut() : Indoor() {

}

std::string Hut::type() {
    return "hut";
}
