#include "actors.hpp"
#include "environments.hpp"
#include "objects.hpp"
#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>

using namespace text_adventure;


std::vector<Actor *> actors;
std::vector<Actor *> demons; // Used for victory condition
std::vector<Environment *> environments;
std::vector<Object * > objects;
Human * player;

/**
 * Initialise the playable game.
 */
void initialise() {
    std::srand(std::time(0));

    /**
     * Create world.
     */

    // Forests
    Environment * env = new Forest();
    environments.emplace_back(env);
    env = new Forest();
    environments.emplace_back(env);
    env = new Forest();
    environments.emplace_back(env);

    environments[0]->add_neighbour(NORTH, environments[1]);
    environments[1]->add_neighbour(SOUTH, environments[0]);
    environments[1]->add_neighbour(EAST, environments[2]);
    environments[2]->add_neighbour(WEST, environments[1]);

    // Caves
    env = new Cave(false);
    environments.emplace_back(env);
    environments[2]->add_neighbour(NORTH, environments[3]);
    environments[3]->add_neighbour(SOUTH, environments[2]);

    env = new Cave(false);
    environments.emplace_back(env);
    environments[3]->add_neighbour(NORTH, environments[4]);
    environments[4]->add_neighbour(SOUTH, environments[3]);

    env = new Cave(false);
    environments.emplace_back(env);
    environments[3]->add_neighbour(WEST, environments[5]);
    environments[5]->add_neighbour(EAST, environments[3]);

    env = new Cave(false);
    environments.emplace_back(env);
    environments[4]->add_neighbour(WEST, environments[6]);
    environments[6]->add_neighbour(EAST, environments[4]);
    environments[5]->add_neighbour(NORTH, environments[6]);
    environments[6]->add_neighbour(SOUTH, environments[5]);

    // Forest opening
    env = new Forest();
    environments.emplace_back(env);
    environments[5]->add_neighbour(WEST, environments[7]);
    environments[7]->add_neighbour(EAST, environments[5]);

    env = new Hut(false);
    environments.emplace_back(env);
    environments[7]->add_neighbour(WEST, environments[8]);
    environments[8]->add_neighbour(EAST, environments[7]);

    // Mountain range
    env = new Mountain();
    environments.emplace_back(env);
    env = new Mountain();
    environments.emplace_back(env);
    env = new Mountain();
    environments.emplace_back(env);

    environments[7]->add_neighbour(NORTH, environments[9]);
    environments[9]->add_neighbour(SOUTH, environments[7]);
    environments[9]->add_neighbour(NORTH, environments[10]);
    environments[10]->add_neighbour(SOUTH, environments[9]);
    environments[10]->add_neighbour(NORTH, environments[11]);
    environments[11]->add_neighbour(SOUTH, environments[10]);

    // Vast desert
    env = new Desert();
    environments.emplace_back(env);
    env = new Desert();
    environments.emplace_back(env);
    env = new Desert();
    environments.emplace_back(env);
    env = new Desert();
    environments.emplace_back(env);
    env = new Desert();
    environments.emplace_back(env);
    env = new Desert();
    environments.emplace_back(env);

    environments[6]->add_neighbour(NORTH, environments[12]);
    environments[12]->add_neighbour(SOUTH, environments[6]);
    environments[11]->add_neighbour(EAST, environments[16]);
    environments[16]->add_neighbour(WEST, environments[11]);

    environments[12]->add_neighbour(EAST, environments[13]);
    environments[13]->add_neighbour(WEST, environments[12]);
    environments[14]->add_neighbour(EAST, environments[15]);
    environments[15]->add_neighbour(WEST, environments[14]);
    environments[16]->add_neighbour(EAST, environments[17]);
    environments[17]->add_neighbour(WEST, environments[16]);

    environments[12]->add_neighbour(NORTH, environments[14]);
    environments[14]->add_neighbour(SOUTH, environments[12]);
    environments[13]->add_neighbour(NORTH, environments[15]);
    environments[15]->add_neighbour(SOUTH, environments[13]);
    environments[14]->add_neighbour(NORTH, environments[16]);
    environments[16]->add_neighbour(SOUTH, environments[14]);
    environments[15]->add_neighbour(NORTH, environments[17]);
    environments[17]->add_neighbour(SOUTH, environments[15]);

    // Final Castle
    env = new Castle(false);
    environments.emplace_back(env);
    env = new Castle(false);
    environments.emplace_back(env);
    env = new Castle(true); // Locked
    environments.emplace_back(env);
    env = new Castle(false);
    environments.emplace_back(env);

    environments[17]->add_neighbour(NORTH, environments[18]);
    environments[18]->add_neighbour(SOUTH, environments[17]);
    environments[18]->add_neighbour(NORTH, environments[19]);
    environments[19]->add_neighbour(SOUTH, environments[18]);
    environments[19]->add_neighbour(WEST, environments[20]);
    environments[20]->add_neighbour(EAST, environments[19]);
    environments[19]->add_neighbour(NORTH, environments[21]);
    environments[21]->add_neighbour(SOUTH, environments[19]);


    /**
     * Place items.
     */

    // Forest
    Object * obj = new Knapsack(10, 10);
    objects.emplace_back(obj);
    environments[1]->drop(obj);
    obj = new Axe();
    objects.emplace_back(obj);
    environments[2]->drop(obj);

    // Cave
    obj = new ElixirOfInvincibility();
    objects.emplace_back(obj);
    environments[4]->drop(obj);
    obj = new Bread();
    objects.emplace_back(obj);
    environments[5]->drop(obj);

    // Forest
    Bottle * bottle = new Bottle(2, 2);
    obj = new Key();
    objects.emplace_back(obj);
    bottle->add(obj);
    obj = bottle;
    objects.emplace_back(obj);
    environments[7]->drop(obj);

    // Hut
    obj = new Bread();
    objects.emplace_back(obj);
    environments[8]->drop(obj);
    obj = new Katana();
    objects.emplace_back(obj);
    environments[8]->drop(obj);
    obj = new ManaPotion();
    objects.emplace_back(obj);
    environments[8]->drop(obj);

    // Mountain
    obj = new Bottle(4, 4);
    objects.emplace_back(obj);
    environments[9]->drop(obj);
    obj = new Key();
    objects.emplace_back(obj);
    environments[10]->drop(obj);
    obj = new Longsword();
    objects.emplace_back(obj);
    environments[11]->drop(obj);

    // Desert
    obj = new ManaPotion();
    objects.emplace_back(obj);
    environments[15]->drop(obj);

    // Castle
    obj = new Pancakes();
    objects.emplace_back(obj);
    environments[18]->drop(obj);
    obj = new Shotgun();
    objects.emplace_back(obj);
    environments[20]->drop(obj);


    /**
     * Spawn monsters.
     */

    // Forest
    Actor * act = new Hedgehog(environments[2], "Igor");
    actors.emplace_back(act);
    environments[2]->enter(act);

    // Caves
    act = new Zombie(environments[3], "Bertha");
    actors.emplace_back(act);
    environments[3]->enter(act);

    // Mountain range
    Dragon * dragon = new Dragon(environments[10], "Smaug");
    actors.emplace_back(dragon);
    environments[10]->enter(dragon);

    // Vast Desert
    act = new Worg(environments[13], "Laika");
    actors.emplace_back(act);
    environments[13]->enter(act);
    act = new Worg(environments[14], "Hugo");
    actors.emplace_back(act);
    environments[14]->enter(act);

    act = new Goblin(environments[17], "Neep");
    actors.emplace_back(act);
    environments[17]->enter(act);

    // Final Castle
    act = new Demon(environments[19], "Tripp");
    actors.emplace_back(act);
    demons.emplace_back(act);
    environments[19]->enter(act);
    act = new Demon(environments[21], "Trapp");
    actors.emplace_back(act);
    demons.emplace_back(act);
    environments[21]->enter(act);
    act = new Demon(environments[21], "Trull");
    actors.emplace_back(act);
    demons.emplace_back(act);
    environments[21]->enter(act);
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
    << "- go      <direction>:  Go to the direction.\n"
    << "- attack  <enemy>:      Attack the enemy.\n"
    << "- take    <item>:       Take the item.\n"
    << "- drop    <item>:       Drop the item.\n"
    << "- choose  <class>:      Select class before starting the game.\n"
    << "- consume <consumable>: Consume the consumable.\n"
    << "- help:      Get this information.\n"
    << "- look:      Get information about your surroundings.\n"
    << "- inventory: Get information about items you are carrying.\n"
    << "- stats:     Get information about your current stats.\n"
    << "- wait:      Skip your turn.\n"
    << "- exit:      Exit the game.\n"
    << std::endl;
}

/**
 * Print the input prompt.
 */
void print_prompt() {
    std::cout << "> ";
}

/**
 * Print the Game Over message.
 */
void print_game_over() {
    std::cout
        << "========================================================\n"
        << "|                    ~ GAME OVER ~                     |\n"
        << "|                                                      |\n"
        << "| You died. Your adventure ends here.                  |\n"
        << "========================================================\n"
    << std::endl;
}

/**
 * Print the Victory message.
 */
void print_victory() {
    std::cout
        << "========================================================\n"
        << "|                     ~ VICTORY ~                      |\n"
        << "|                                                      |\n"
        << "| Congratulations, you won the game.                   |\n"
        << "========================================================\n"
    << std::endl;
}

/**
 * Split the given string using the given delimiter.
 */
std::vector<std::string> split(const std::string & s, const char delim) {
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
        player = new Warrior(environments[0], "Ulf");
    } else if (clss == "wizard") {
        std::cout << "You chose to be a fabulous wizard." << std::endl;
        player = new Wizard(environments[0], "Gondolf");
    } else if (clss == "peasant") {
        std::cout << "You chose to be a dirty peasant." << std::endl;
        player = new Peasant(environments[0], "Unnamed");
    } else {
        return false;
    }
    return true;
}

/**
 * Go to the given direction.
 * Return false if the direction is invalid.
 */
bool go_to(const std::string & direction) {
    Environment * room = player->get_room();

    if (direction == "n" || direction == "north") {
        if (!room->neighbour(NORTH)) {
            std::cout << "There is no exit in that direction." << std::endl;
            return false;
        }
        if (!player->go(NORTH)) {
            std::cout << "The room is locked." << std::endl;
            return false;
        }
    } else if (direction == "e" || direction == "east") {
        if (!room->neighbour(EAST)) {
            std::cout << "There is no exit in that direction." << std::endl;
            return false;
        }
        if (!player->go(EAST)) {
            std::cout << "The room is locked." << std::endl;
            return false;
        }
    } else if (direction == "s" || direction == "south") {
        if (!room->neighbour(SOUTH)) {
            std::cout << "There is no exit in that direction." << std::endl;
            return false;
        }
        if (!player->go(SOUTH)) {
            std::cout << "The room is locked." << std::endl;
            return false;
        }
    } else if (direction == "w" || direction == "west") {
        if (!room->neighbour(WEST)) {
            std::cout << "There is no exit in that direction." << std::endl;
            return false;
        }
        if (!player->go(WEST)) {
            std::cout << "The room is locked." << std::endl;
            return false;
        }
    } else {
        std::cout << "Invalid direction." << std::endl;
        return false;
    }

    return true;
}

/**
 * Call all actors' action functions.
 */
void act() {
    for (const auto & actor : actors) {
        if(actor->is_dead())
            continue;

        std::string a = actor->action();
        if(a != "")
            std::cout << "*** " << a << " ***\n" << std::endl;

        actor->update();
    }

    for (const auto & environment : environments) {
        if (Outdoor * const outdoor = dynamic_cast<Outdoor *>(environment))
            outdoor->update();
    }

    player->update();
}

/**
 * Return true if the victor condition is met, i.e. all demons in the
 * castle have been killed.
 */
bool victory() {
    for (const auto & demon : demons) {
        if (!demon->is_dead())
            return false;
    }

    return true;
}

/**
 * Start and run the gameplay loop which reads player input and acts
 * accordingly.
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

        // Class selection
        if (!started) {
            if (cmds.size() > 0 && cmds[0] == "choose") {
                if (cmds.size() < 2) {
                    std::cout << "Who do you want to be?" << std::endl;
                } else {
                    if (choose_class(cmds[1])) {
                        started = true;
                        std::cout << std::endl << player->look();
                    } else {
                        std::cout << "Invalid class." << std::endl;
                    }
                }
            } else {
                std::cout << "You must choose a class before continuing." << std::endl;
            }
            std::cout << std::endl;
            print_prompt();
            continue;
        }

        // General gameplay
        if (cmds.size() > 0 && cmds[0] == "go") {
            if (cmds.size() < 2) {
                std::cout << "Go where?" << std::endl;
            } else {
                if (go_to(cmds[1])) {
                    act();
                    std::cout << player->look();
                }
            }
        } else if (cmds.size() > 0 && cmds[0] == "take") {
            if (cmds.size() < 2) {
                std::cout << "Take what?" << std::endl;
            } else {
                if (!player->pick_up(cmds[1]))
                    std::cout << "You can not take that." << std::endl;
            }
        } else if (cmds.size() > 0 && cmds[0] == "drop") {
            if (cmds.size() < 2) {
                std::cout << "Drop what?" << std::endl;
            } else {
                if (!player->drop(cmds[1]))
                    std::cout << "You do not carry that." << std::endl;
            }
        } else if (cmds.size() > 0 && cmds[0] == "attack") {
            if (cmds.size() < 2) {
                std::cout << "Attack what?" << std::endl;
            } else {
                auto monsters = player->get_room()->monsters();
                Actor * enemy = nullptr;
                for(Actor * m : monsters) {
                    if(m->name() == cmds[1]) {
                        enemy = m;
                        break;
                    }
                }
                if(enemy == nullptr) {
                    std::cout << "There is no enemy with that name." << std::endl;
                } else {
                    std::cout << player->fight(enemy) << std::endl;
                    act();
                }
            }
        } else if (cmds.size() > 0 && cmds[0] == "consume") {
            if (cmds.size() < 2) {
                std::cout << "Consume what?" << std::endl;
            } else {
                if (!player->consume(cmds[1]))
                    std::cout << "You can not consume that." << std::endl;
            }
        } else if (cmd == "choose" || (cmds.size() > 0 && cmds[0] == "choose")) {
            std::cout << "You may not change your class." << std::endl;
        } else if (cmd == "look") {
            std::cout << player->look();
        } else if (cmd == "inventory" || cmd == "inv") {
            std::cout << player->items();
        } else if (cmd == "stats") {
            std::cout << player->statistics();
        } else if (cmd == "wait") {
            act();
        } else if (cmd == "") {
            // Ignore
        } else {
            std::cout << "I don't know what '" << cmd << "' means." << std::endl;
        }
        std::cout << std::endl;

        // Check for failure state
        if (player->is_dead()) {
            print_game_over();
            break;
        } else if (victory()) {
            print_victory();
            break;
        }

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
