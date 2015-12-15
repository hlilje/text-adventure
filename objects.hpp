#pragma once

#include <algorithm>
#include <string>
#include <unordered_set>

namespace text_adventure {
    class Object {
        private:
            const std::string _type;
            const int _volume;
            const int _weight;
            const bool _is_liquid;

        public:
            Object(std::string const & type, int const vol, int const weight,
                   bool const liquid);
            virtual ~Object() = default;

            std::string type() const;
            bool is_liquid() const;
            int volume() const;
            int weight() const;
    };

    class Container : public Object {
        private:
            const bool _holds_liquid;
            const int _max_volume;
            const int _max_weight;

            std::unordered_set<Object *> _objects;
        public:
            Container(std::string const & type, int const vol, int const weight,
                      bool const liquid, const int max_volume,
                      const int max_weight, const bool holds_liquid);
            ~Container() override = default;

            /**
             * Try to add the given object.
             * Return true if successful.
             */
            bool add(Object * const object);
            /**
             * Try to remove the given object.
             * Return true if successful.
             */
            bool remove(Object * const object);
            /**
             * Return the item with the given type.
             * Return nullptr if no such type exists.
             */
            Object * find(const std::string & type) const;
            int max_volume() const;
            int max_weight() const;
            std::unordered_set<Object *> const & contents() const;
    };

    class Consumable : public Object {
        public:
            Consumable(std::string const & type, int const vol, int const weight,
                       bool const liquid);
            ~Consumable() override = default;
    };

    class Weapon : public Object {
        private:
            const int _damage;

        public:
            Weapon(std::string const & type, int const vol, int const weight,
                   int const damage);
            ~Weapon() override = default;

            int damage() const;
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

    class Bottle : public Container {
        public:
            Bottle(const int max_volume, const int max_weight);
            ~Bottle() override = default;
    };

    class Food : public Consumable {
        private:
            const int _health;

        public:
            Food(std::string const & type, int const vol, int const weight,
                 int const health);
            ~Food() override = default;

            int health() const;
    };

    class Bread : public Food {
        public:
            Bread();
            ~Bread() override = default;
    };

    class Pancakes : public Food {
        public:
            Pancakes();
            ~Pancakes() override = default;
    };

    class Potion : public Consumable {
        private:
            const int _health;
            const int _mana;

        public:
            Potion(std::string const & type, int const vol, int const weight,
                   int const health, int const mana);
            ~Potion() override = default;

            int health() const;
            int mana() const;
    };

    class ManaPotion : public Potion {
        public:
            ManaPotion();
            ~ManaPotion() override = default;
    };

    class ElixirOfInvincibility : public Potion {
        public:
            ElixirOfInvincibility();
            ~ElixirOfInvincibility() override = default;
    };

    class Shotgun : public Weapon {
        public:
            Shotgun();
            ~Shotgun() override = default;
    };

    class Axe : public Weapon {
        public:
            Axe();
            ~Axe() override = default;
    };

    class Sword : public Weapon {
        public:
            Sword(std::string const & type, int const vol,
                  int const weight, int const damage);
            ~Sword() override = default;
    };

    class Longsword : public Sword {
        public:
            Longsword();
            ~Longsword() override = default;
    };

    class Katana : public Sword {
        public:
            Katana();
            ~Katana() override = default;
    };
}
