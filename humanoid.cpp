#include "actors.hpp"

using namespace text_adventure;


Humanoid::Humanoid(int const health,
                   int const attack_damage,
                   Environment * const room,
                   std::string const type,
                   std::string const name)
    : Actor(health, attack_damage, room, type, name) {}

std::string Humanoid::action() {
    return "";
}

std::string Humanoid::fight(Actor * const character) {
    return "";
}
