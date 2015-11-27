#include "actors.hpp"
#include "environments.hpp"
#include "objects.hpp"
#include <iostream>
#include <sstream>
#include <vector>

using namespace text_adventure;


std::vector<Actor *> actors;
std::vector<Environment *> environments;
std::vector<Object * > objects;

/**
 * Initialise the playable game
 */
void initialise() {
    Forest * forest = new Forest();
    environments.emplace_back(forest);
}

/**
 * Print the welcome startup message.
 */
void print_greeting() {
    std::cout
        << "========================================================\n"
        << "|                  ~ TEXT ADVENTURE ~                  |\n"
        << "|                                                      |\n"
        << "| Welcome to the adventure of your life. You are a     |\n"
        << "| human playing a generic text-based adventure game on |\n"
        << "| a computer.                                          |\n"
        << "| Only one thing is certain; it is time to pick your   |\n"
        << "| class.                                               |\n"
        << "| Enter 'start x' with x = 1 for Warrior, 2 for Mage,  |\n"
        << "| and 3 for Peasant.                                   |\n"
        << "========================================================\n"
        << "\n"
        << "Commands:\n"
        << "- go: GO.\n"
        << "- exit: Exit the game.\n"
    << std::endl;
}

void split(const std::string &s, const char delim,
           std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
        elems.push_back(item);
}

std::vector<std::string> split(const std::string &s, const char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);

    return elems;
}

void act() {
    for (const auto & actor : actors)
        actor->action();
}

/**
 * Start and run the gameplay loop.
 */
void run() {
    print_greeting();

    for (std::string cmd; std::getline(std::cin, cmd);) {
        std::vector<std::string> cmds = split(cmd, ' ');
        if (cmd == "exit") {
            break;
        } else if (cmds.size() > 2) {
            std::cout << "I only understand two words at a time." << std::endl;
        } else if (cmds.size() > 0 && cmds[0] == "go") {
            if (cmds.size() < 2) {
                std::cout << "Go where?" << std::endl;
                continue;
            }
            std::cout << "GO" << std::endl;
            act();
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
