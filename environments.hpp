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
            std::string description() const;
            std::unordered_set<Actor *> const & monsters() const;
            std::unordered_set<Object *> const & objects() const;
            std::vector<Direction> directions() const;
            Environment * neighbour(const Direction dir) const;
            void add_neighbour(Direction dir, Environment * const room);
            void enter(Actor * const character);
            void exit(Actor * const character);
            void pick_up(Object * const object);
            void drop(Object * const object);

            virtual std::string type() const = 0;
    };

    class Outdoor : public Environment {
        private:
            Weather _weather;

        public:
            Outdoor();
            ~Outdoor() override = default;

            std::string weather() const;
            /**
             * Update the environment, such as its weather.
             */
            void update();
    };

    class Forest : public Outdoor {
        public:
            Forest();
            ~Forest() override = default;

            std::string type() const override;
    };

    class Desert : public Outdoor {
        public:
            Desert();
            ~Desert() override = default;

            std::string type() const override;
    };

    class Mountain : public Outdoor {
        public:
            Mountain();
            ~Mountain() override = default;

            std::string type() const override;
    };

    class Indoor : public Environment {
        private:
            bool _locked;

        public:
            Indoor(const bool locked);
            ~Indoor() override = default;

            bool is_locked() const;
    };


    class Cave : public Indoor {
        public:
            Cave(const bool locked);
            ~Cave() override = default;

            std::string type() const override;
    };
    class Castle : public Indoor {
        public:
            Castle(const bool locked);
            ~Castle() override = default;

            std::string type() const override;
    };

    class Hut : public Indoor {
        public:
            Hut(const bool locked);
            ~Hut() override = default;

            std::string type() const override;
    };
}
