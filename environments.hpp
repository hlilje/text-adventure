#pragma once

#include "objects.hpp"
#include <string>
#include <unordered_set>
#include <vector>


namespace text_adventure {
    enum Direction {NORTH, EAST, SOUTH, WEST};
    enum Weather {SUNNY, RAINY, WINDY};

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
            std::unordered_set<Object *> const & objects() const;
            std::vector<Direction> directions();
            Environment * neighbour(const Direction dir);
            void enter(Actor * const character);
            void exit(Actor * const character);
            void pick_up(Object * const object);
            void drop(Object * const object);

            virtual std::string type() = 0;
    };

    class Outdoor : public Environment {
        private:
            Weather _weather;

        public:
            Outdoor();
            ~Outdoor() override = default;

            std::string weather();
            /**
             * Update the environment, such as its weather.
             */
            void update();
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
