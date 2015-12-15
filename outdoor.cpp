#include "environments.hpp"

using namespace text_adventure;


Outdoor::Outdoor() : Environment(), _weather(SUNNY) {}

std::string Outdoor::weather() const {
    switch (_weather) {
        case SUNNY:
            return "sunny";
        case RAINY:
            return "rainy";
        case WINDY:
            return "windy";
        default:
            return "";
    }
}

void Outdoor::update() {
    int n = std::rand() % 100;

    if (type() == "forest") {
        if (n >= 0  && n < 50)  _weather = RAINY;
        if (n >= 50 && n < 80)  _weather = SUNNY;
        if (n >= 80 && n < 100) _weather = WINDY;
    } else if (type() == "desert") {
        if (n >= 0  && n < 80)  _weather = SUNNY;
        if (n >= 80 && n < 100) _weather = WINDY;
    } else if (type() == "mountain") {
        if (n >= 0  && n < 70)  _weather = WINDY;
        if (n >= 70 && n < 90)  _weather = SUNNY;
        if (n >= 90 && n < 100) _weather = RAINY;
    }
}
