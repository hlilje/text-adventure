#include "actors.hpp"
#include "environments.hpp"
#include "objects.hpp"
#include <vector>

using namespace text_adventure;


std::vector<Actor *> actors;
std::vector<Environment *> environments;
std::vector<Object * > objects;

/**
 * Initialise the playable game
 */
void initialise() {

}

/**
 * Start and run the gameplay loop.
 */
void run() {
}

/**
 * Free all allocated memory.
 */
void cleanup() {
    for (const auto & actor : actors)
        delete actor;
    for (const auto & environment : environments)
        delete environment;
    for (const auto & object : objects)
        delete object;
}

int main() {
    initialise();
    run();
    cleanup();

    return 0;
}
