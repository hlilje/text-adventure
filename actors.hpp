#pragma once

#include "objects.hpp"
#include <string>


namespace text_adventure {

    class Actor {
        private:
            int _health;
            std::string _name;
            std::string _type;

        public:
            Actor();

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
            Human();

            void go(const Direction direction) override;
            void action() override;
            void drop(const Object & object) override;
            void fight(const Actor & character) override;
            void pick_up(const Object & object) override;
    };

    class Peasant : public Human {
        public:
            Peasant();

            void go(const Direction direction) override;
            void action() override;
            void drop(const Object & object) override;
            void fight(const Actor & character) override;
            void pick_up(const Object & object) override;
    };
}
