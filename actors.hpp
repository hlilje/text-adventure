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
            virtual void action() = 0;
            virtual void drop(const Object & object) = 0;
            virtual void fight(const Actor & character) = 0;
            virtual void pick_up(const Object & object) = 0;
    };

    class Human : public Actor {
        public:
            Human(Environment * const room, std::string const type, std::string const name);
            ~Human() override = default;

            void go(const Direction direction) override;
            void action() override;
            void drop(const Object & object) override;
            void fight(const Actor & character) override;
            void pick_up(const Object & object) override;
            std::string look();
    };

    class Warrior : public Human {
        public:
            Warrior(Environment * const room, std::string const name);
            ~Warrior() override = default;

            void action() override;
            void drop(const Object & object) override;
            void fight(const Actor & character) override;
            void pick_up(const Object & object) override;
    };

    class Wizard : public Human {
        public:
            Wizard(Environment * const room, std::string const name);
            ~Wizard() override = default;

            void action() override;
            void drop(const Object & object) override;
            void fight(const Actor & character) override;
            void pick_up(const Object & object) override;
    };

    class Peasant : public Human {
        public:
            Peasant(Environment * const room, std::string const name);
            ~Peasant() override = default;

            void action() override;
            void drop(const Object & object) override;
            void fight(const Actor & character) override;
            void pick_up(const Object & object) override;
    };

    class Creature : public Actor {
        public:
            Creature(Environment * const room, std::string const type, std::string const name);
            ~Creature() override = default;

            void action() override;
            void drop(const Object & object) override;
            void fight(const Actor & character) override;
            void pick_up(const Object & object) override;
    };

    class Hedgehog : public Creature {
        public:
            Hedgehog(Environment * const room, std::string const name);
            ~Hedgehog() override = default;

            void action() override;
            void drop(const Object & object) override;
            void fight(const Actor & character) override;
            void pick_up(const Object & object) override;
    };
}
