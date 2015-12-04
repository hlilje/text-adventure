#pragma once

#include <algorithm>
#include <iostream>
#include <string>
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

            /**
             * Try to add the given object.
             * Return true if successful.
             */
            bool add(Object * const object);
            void remove(Object * const object);
            /**
             * Return the item with the given type.
             * Return nullptr if no such type exists.
             */
            Object * find(const std::string & type) const;
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
