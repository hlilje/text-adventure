#pragma once

#include "environments.hpp"
#include "objects.hpp"
#include <string>


namespace text_adventure {
    class Actor {
        protected:
            int _health;
            Environment * _room;
            std::string _type;
            std::string _name;

        public:
            Actor(Environment * const room, std::string const type, std::string const name);
            virtual ~Actor() = default;

            std::string name();
            std::string type();

            Environment * get_room();

            virtual void go(const Direction direction);
            /**
             * Make the actor act.
             */
            virtual void action() = 0;
            virtual void fight(Actor * const character) = 0;
    };

    class Human : public Actor {
        private:
            const Object * _hand;
            // Container * _back; // TODO

        public:
            Human(Environment * const room, std::string const type, std::string const name);
            ~Human() override = default;

            void go(const Direction direction) override;
            void action() override;
            void drop(const Object * const object);
            void fight(Actor * const character);
            /**
             * Try to pick up the given object.
             * Return false if there is no room to pick it up.
             */
            bool pick_up(const Object * const object);
            std::string look();
    };

    class Warrior : public Human {
        public:
            Warrior(Environment * const room, std::string const name);
            ~Warrior() override = default;

            void action() override;
            void fight(Actor * const character) override;
    };

    class Wizard : public Human {
        public:
            Wizard(Environment * const room, std::string const name);
            ~Wizard() override = default;

            void action() override;
            void fight(Actor * const character) override;
    };

    class Peasant : public Human {
        public:
            Peasant(Environment * const room, std::string const name);
            ~Peasant() override = default;

            void action() override;
            void fight(Actor * const character) override;
    };

    class Creature : public Actor {
        public:
            Creature(Environment * const room, std::string const type, std::string const name);
            ~Creature() override = default;

            void action() override;
            void fight(Actor * const character) override;
    };

    class Hedgehog : public Creature {
        public:
            Hedgehog(Environment * const room, std::string const name);
            ~Hedgehog() override = default;

            void action() override;
            void fight(Actor * const character) override;
    };
}
