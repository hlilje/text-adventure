#pragma once

#include "environments.hpp"
#include "objects.hpp"
#include <string>


namespace text_adventure {
    class Actor {
        protected:
            int _health;
            std::string _name;
            std::string _type;
            Environment * _room;

        public:
            Actor(Environment * room);
            virtual ~Actor() = default;

            std::string name();
            std::string type();

            virtual void go(const Direction direction);
            virtual void action() = 0;
            virtual void drop(const Object & object) = 0;
            virtual void fight(const Actor & character) = 0;
            virtual void pick_up(const Object & object) = 0;
    };

    class Human : public Actor {
        public:
            Human(Environment * room);
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
            Warrior(Environment * room);
            ~Warrior() override = default;

            void go(const Direction direction) override;
            void action() override;
            void drop(const Object & object) override;
            void fight(const Actor & character) override;
            void pick_up(const Object & object) override;
    };

    class Wizard : public Human {
        public:
            Wizard(Environment * room);
            ~Wizard() override = default;

            void go(const Direction direction) override;
            void action() override;
            void drop(const Object & object) override;
            void fight(const Actor & character) override;
            void pick_up(const Object & object) override;
    };

    class Peasant : public Human {
        public:
            Peasant(Environment * room);
            ~Peasant() override = default;

            void go(const Direction direction) override;
            void action() override;
            void drop(const Object & object) override;
            void fight(const Actor & character) override;
            void pick_up(const Object & object) override;
    };

    class Creature : public Actor {
        public:
            Creature(Environment * room);
            ~Creature() override = default;

            void go(const Direction direction) override;
            void action() override;
            void drop(const Object & object) override;
            void fight(const Actor & character) override;
            void pick_up(const Object & object) override;
    };

    class Hedgehog : public Creature {
        public:
            Hedgehog(Environment * room);
            ~Hedgehog() override = default;

            void go(const Direction direction) override;
            void action() override;
            void drop(const Object & object) override;
            void fight(const Actor & character) override;
            void pick_up(const Object & object) override;
    };
}
