#include "actors.hpp"
#include "environments.hpp"

using namespace text_adventure;


Cave::Cave() : Indoor() {

}

std::string Cave::type() {
    return "cave";
}
