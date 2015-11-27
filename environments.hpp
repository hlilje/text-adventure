#pragma once

#include "objects.hpp"
#include <string>
#include <vector>
#include <unordered_set>


namespace text_adventure {
    enum Direction {NORTH, EAST, SOUTH, WEST};

    class Actor;

    class Environment {
        private:
            std::unordered_set<Actor *> _actors;
            std::unordered_set<Object *> _objects;
            std::vector<Environment *> _neighbours;

        public:
            Environment();
            virtual ~Environment() = default;

            std::string description();

            virtual std::vector<Direction> directions();
            virtual Environment * neighbour(const Direction dir);
            virtual void enter(Actor * const character);
            virtual void exit(Actor * const character);
            virtual void pick_up(Object * const object);
            virtual void drop(Object * const object);
            virtual std::string type() = 0;
    };

    class Outdoor : public Environment {
        public:
            Outdoor();
            ~Outdoor() override = default;

            virtual void weather();
    };

    class Forest : public Outdoor {
        public:
            Forest();
            ~Forest() override = default;

            virtual std::string type() override;
    };
}
