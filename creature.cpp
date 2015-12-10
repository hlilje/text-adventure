#include "actors.hpp"

using namespace text_adventure;


Creature::Creature(int const health,
                   int const attack_damage,
                   Environment * const room,
                   std::string const type,
                   std::string const name)
    : Actor(health, attack_damage, room, type, name) {}

std::string Creature::action() {
    return "";
}

std::string Creature::fight(Actor * const character) {
    return "";
};
