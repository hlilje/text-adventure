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
        << "| Enter 'choose x' with x = 1 for Warrior, 2 for Mage, |\n"
        << "| and 3 for Peasant.                                   |\n"
        << "========================================================\n"
    << std::endl;
}

/**
 * Print the help text.
 */
void print_help() {
    std::cout
    << "Commands:\n"
    << "- go: GO.\n"
    << "- exit: Exit the game.\n"
    << std::endl;
}

/**
 * Print the input prompt.
 */
void print_prompt() {
    std::cout << "> ";
}

/**
 * Split the given string using the given delimiter.
 */
std::vector<std::string> split(const std::string &s, const char delim) {
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, delim))
        elems.push_back(item);

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
    print_help();

    bool started = false;
    print_prompt();
    for (std::string cmd; std::getline(std::cin, cmd);) {
        std::vector<std::string> cmds = split(cmd, ' ');

        if (cmd == "exit") break;

        if (cmd == "help") {
            print_help();
            print_prompt();
            continue;
        }

        if (cmds.size() > 2) {
            std::cout << "I only understand two words at a time." << std::endl;
            std::cout << std::endl;
            print_prompt();
            continue;
        }

        if (!started) {
            if (cmds.size() > 0 && cmds[0] == "choose") {
                if (cmds.size() < 2) {
                    std::cout << "Who do you want to be?" << std::endl;
                } else {
                    std::cout << "CHOOSE" << std::endl;
                    started = true;
                }
            } else {
                std::cout << "You must choose a class before continuing." << std::endl;
            }
            std::cout << std::endl;
            print_prompt();
            continue;
        }

        if (cmds.size() > 0 && cmds[0] == "go") {
            if (cmds.size() < 2) {
                std::cout << "Go where?" << std::endl;
            } else {
                std::cout << "GO" << std::endl;
                act();
            }
        } else if (cmds.size() > 0 && cmds[0] == "pickup") {
            if (cmds.size() < 2) {
                std::cout << "Pick what up?" << std::endl;
            } else {
                std::cout << "PICKUP" << std::endl;
                act();
            }
        } else if (cmds.size() > 0 && cmds[0] == "drop") {
            if (cmds.size() < 2) {
                std::cout << "Drop what?" << std::endl;
            } else {
                std::cout << "DROP" << std::endl;
                act();
            }
        } else if (cmds.size() > 0 && cmds[0] == "attack") {
            if (cmds.size() < 2) {
                std::cout << "Attack what?" << std::endl;
            } else {
                std::cout << "ATTACK" << std::endl;
                act();
            }
        } else if (cmd == "look") {
            std::cout << "LOOK" << std::endl;
        } else if (cmd == "") {
            // Ignore
        } else {
            std::cout << "I don't know what '" << cmd << "' means." << std::endl;
        }
        std::cout << std::endl;
        print_prompt();
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
