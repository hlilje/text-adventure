#pragma once

#include <string>
#include <iostream>
#include <unordered_set>

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

            std::string type() const;
            bool is_liquid() const;
            int volume() const;
            int weight() const;
    };

    class Container : public Object {
        private:
            bool _holds_liquid;
            int _max_volume;
            int _max_weight;

            std::unordered_set<Object *> _objects;
        public:
            Container(std::string const type, int const vol,
                      int const weight, bool const liquid,
                      const int max_volume, const int max_weight,
                      const bool holds_liquid);
            ~Container() override = default;

            bool add(Object * const object);
            int max_volume() const;
            int max_weight() const;
            void remove(Object * const object);
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
            Knapsack(const int max_volume, const int max_weight);
            ~Knapsack() override = default;
    };
}
