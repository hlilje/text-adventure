#pragma once

#include <string>
#include <iostream>

namespace text_adventure {
    class Object {
        private:
            std::string _type;
            int _volume;
            int _weight;
            bool _is_liquid;

        public:
            Object(std::string const type, int const vol,
                   int const weight, bool const liquid);
            virtual ~Object() = default;

            std::string type();
            bool is_liquid();
            int volume();
            int weight();
    };

    class Container : public Object {
        public:
            Container();
            ~Container() override = default;

            int add(const Object & object);
            int max_volume();
            int max_weight();
            int remove(const Object & object);
    };

    class Consumable : public Object {
        public:
            Consumable();
            ~Consumable() override = default;
    };

    class Weapon : public Object {
        public:
            Weapon();
            ~Weapon() override = default;
    };

    class Key : public Object {
        public:
            Key();
            ~Key() override = default;
    };

    class Knapsack : public Container {
        public:
            Knapsack();
            ~Knapsack() override = default;
    };
}
