#pragma once

#include "objects.hpp"
#include <string>
#include <unordered_set>
#include <vector>


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

            /**
             * Return a description string of location, items, directions and
             * monsters.
             */
            std::string description();
            std::unordered_set<Actor *> const & monsters();
            void add_neighbour(Direction dir, Environment * const room);
            std::unordered_set<Object *> & objects();

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

    class Desert : public Outdoor {
        public:
            Desert();
            ~Desert() override = default;

            virtual std::string type() override;
    };

    class Mountain : public Outdoor {
        public:
            Mountain();
            ~Mountain() override = default;

            virtual std::string type() override;
    };

    class Indoor : public Environment {
        public:
            Indoor();
            ~Indoor() override = default;
    };


    class Cave : public Indoor {
        public:
            Cave();
            ~Cave() override = default;

            virtual std::string type() override;
    };
    class Castle : public Indoor {
        public:
            Castle();
            ~Castle() override = default;

            virtual std::string type() override;
    };

    class Hut : public Indoor {
        public:
            Hut();
            ~Hut() override = default;

            virtual std::string type() override;
    };
}
