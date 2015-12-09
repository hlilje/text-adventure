#pragma once

#include "environments.hpp"
#include "objects.hpp"
#include <algorithm>
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

            std::string name() const;
            std::string type() const;

            Environment * get_room() const;

            virtual void go(const Direction direction);
            /**
             * Make the actor act.
             */
            virtual void action() = 0;
            virtual void fight(Actor * const character) = 0;
    };

    class Human : public Actor {
        private:
            Object * _hand;
            Container * _back;

        public:
            Human(Environment * const room, std::string const type, std::string const name);
            ~Human() override = default;

            /**
             * Try to drop the given object.
             * Return false if the object is not carried.
             */
            bool drop(const std::string & item);
            void fight(const std::string & character);
            /**
             * Try to pick up the given object.
             * Return false if there is no room to pick it up.
             */
            bool pick_up(const std::string & item);
            std::string look();

            void go(const Direction direction) override;
            void action() override;
            std::string items();
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

    class Dragon : public Creature {
        public:
            Dragon(Environment * const room, std::string const name);
            ~Dragon() override = default;

            void action() override;
            void fight(Actor * const character) override;
    };

    class Worg : public Creature {
        public:
            Worg(Environment * const room, std::string const name);
            ~Worg() override = default;

            void action() override;
            void fight(Actor * const character) override;
    };

    class Humanoid : public Actor {
        public:
            Humanoid(Environment * const room, std::string const type, std::string const name);
            ~Humanoid() override = default;

            void action() override;
            void fight(Actor * const character) override;
    };

    class Demon : public Humanoid {
        public:
            Demon(Environment * const room, std::string const name);
            ~Demon() override = default;

            void action() override;
            void fight(Actor * const character) override;
    };

    class Goblin : public Humanoid {
        public:
            Goblin(Environment * const room, std::string const name);
            ~Goblin() override = default;

            void action() override;
            void fight(Actor * const character) override;
    };

    class Zombie : public Humanoid {
        public:
            Zombie(Environment * const room, std::string const name);
            ~Zombie() override = default;

            void action() override;
            void fight(Actor * const character) override;
    };
}
