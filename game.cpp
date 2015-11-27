#include "actors.hpp"
#include "environments.hpp"
#include "objects.hpp"
#include <iostream>
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
 * Print the welcome startup message.
 */
void print_greeting() {
    std::cout
        << "========================================================\n"
        << "|                    TEXT ADVENTURE                    |\n"
        << "|                                                      |\n"
        << "| Welcome to the adventure of your life. You are a     |\n"
        << "| human playing a generic text-based adventure game on |\n"
        << "| a computer.                                          |\n"
        << "| Only one thing is certain; it is time to pick your   |\n"
        << "| class.                                               |\n"
        << "| Enter 1 for x, 2 for y, 3 for z.                     |\n"
        << "========================================================\n"
        << "\n"
        << "Commands:\n"
        << "- go: GO.\n"
        << "- exit: Exit the game.\n"
    << std::endl;
}

/**
 * Start and run the gameplay loop.
 */
void run() {
    print_greeting();

    for (std::string cmd; std::getline(std::cin, cmd);) {
        if (cmd == "exit") {
            break;
        } else if (cmd == "go") {
            std::cout << "GO" << std::endl;
        } else if (cmd == "") {
            // Ignore
        } else {
            std::cout << "Unknown command: " << cmd << std::endl;
        }
    }
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
