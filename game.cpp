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
Human * player;

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
        << "| Enter 'choose <class>', where <class> must be        |\n"
        << "| 'warrior', 'wizard' or 'peasant'.                    |\n"
        << "========================================================\n"
    << std::endl;
}

/**
 * Print the help text.
 */
void print_help() {
    std::cout
    << "Commands:\n"
    << "- go     <direction>: Go to the direction.\n"
    << "- attack <enemy>:     Attack the enemy.\n"
    << "- take   <item>:      Take the item.\n"
    << "- drop   <item>:      Drop the item.\n"
    << "- choose <class>:     Select class before starting the game.\n"
    << "- help: Get this information.\n"
    << "- look: Get information about your surroundings.\n"
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

/**
 * Choose the given class.
 * Return false if the class is invalid.
 */
bool choose_class(const std::string & clss) {
    if (clss == "warrior") {
        std::cout << "You chose to be a mighty warrior." << std::endl;
    } else if (clss == "wizard") {
        std::cout << "You chose to be a fabulous wizard." << std::endl;
    } else if (clss == "peasant") {
        std::cout << "You chose to be a dirty peasant." << std::endl;
    } else {
        return false;
    }
    return true;
}

/**
 * Call all actors' action functions.
 */
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
                    if (choose_class(cmds[1]))
                        started = true;
                    else
                        std::cout << "Invalid option." << std::endl;
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
        } else if (cmds.size() > 0 && cmds[0] == "take") {
            if (cmds.size() < 2) {
                std::cout << "Take up?" << std::endl;
            } else {
                std::cout << "TAKE" << std::endl;
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
        } else if (cmd == "choose" || (cmds.size() > 0 && cmds[0] == "choose")) {
            std::cout << "You may not change your class." << std::endl;
        } else if (cmd == "look") {
            std::cout << player->look() << std::endl;
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
    delete player;
}

int main() {
    initialise();
    run();
    cleanup();

    return 0;
}
