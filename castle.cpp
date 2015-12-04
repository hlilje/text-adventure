#include "actors.hpp"
#include "environments.hpp"

using namespace text_adventure;


Castle::Castle() : Indoor() {

}

std::string Castle::type() {
    return "castle";
}
