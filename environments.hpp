#pragma once

#include "objects.hpp"
#include <string>
#include <vector>


namespace text_adventure {
    enum Direction {NORTH, EAST, SOUTH, WEST};

    class Actor;

    class Environment {
        private:
            std::vector<Actor *> _actors;
            std::vector<Object *> _objects;
            std::vector<Environment *> _neighbours;

        public:
            Environment();
            virtual ~Environment() = default;

            std::string description();

            virtual std::vector<Direction> directions();
            virtual Environment * neighbour(const Direction dir);
            virtual void enter(const Actor & character);
            virtual void exit(const Actor & character);
            virtual void pick_up(const Object & object);
            virtual void drop(const Object & object);
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
