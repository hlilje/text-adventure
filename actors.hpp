#pragma once

#include "environments.hpp"
#include "objects.hpp"
#include <algorithm>
#include <string>


namespace text_adventure {
    class Actor {
        protected:
            int _health;
            const int _attack_damage;
            int _invincibility_timer;
            bool _invincible;
            Environment * _room;
            const std::string _type;
            const std::string _name;

        public:
            Actor(int const health, int const attack_damage,
                  Environment * const room, std::string const & type,
                  std::string const & name);
            virtual ~Actor() = default;

            std::string name() const;
            std::string type() const;
            bool is_dead() const;
            Environment * get_room() const;
            void update();
            int take_damage(int const damage);
            /**
             * Try to go to the given direction, return false if it
             * is not possible.
             */
            bool go(const Direction direction);

            virtual bool has_item(std::string const & item) const;
            /**
             * Make the actor act.
             */
            virtual std::string action() = 0;
            virtual std::string fight(Actor * const character) = 0;
    };

    class Human : public Actor {
        protected:
            Object * _hand;
            Container * _back;

        public:
            Human(int const health, int const attack_damage,
                  Environment * const room, std::string const & type,
                  std::string const & name);
            ~Human() override = default;

            bool has_item(std::string const & item) const override;

            /**
             * Try to consume the given consumable.
             * Return false if it is not in inventory.
             */
            bool consume(const std::string & consumable);
            /**
             * Try to drop the given object.
             * Return false if the object is not carried.
             */
            bool drop(const std::string & item);
            /**
             * Try to pick up the given object.
             * Return false if there is no room to pick it up.
             */
            bool pick_up(const std::string & item);
            std::string look() const;
            std::string items() const;

            /**
             * Helper function to update stats from consumable.
             * Returns false if object not a consumable.
             */
            virtual bool consume_object(Object * const object);
            virtual std::string statistics() const;
    };

    class Warrior : public Human {
        public:
            Warrior(Environment * const room, std::string const & name);
            ~Warrior() override = default;

            std::string action() override;
            std::string fight(Actor * const character) override;
    };

    class Wizard : public Human {
        private:
            int _mana;

        public:
            Wizard(Environment * const room, std::string const & name);
            ~Wizard() override = default;

            std::string action() override;
            std::string fight(Actor * const character) override;
            bool consume_object(Object * const object) override;
            std::string statistics() const override;
    };

    class Peasant : public Human {
        public:
            Peasant(Environment * const room, std::string const & name);
            ~Peasant() override = default;

            std::string action() override;
            std::string fight(Actor * const character) override;
    };

    class Creature : public Actor {
        public:
            Creature(int const health, int const attack_damage,
                     Environment * const room, std::string const & type,
                     std::string const & name);
            ~Creature() override = default;
    };

    class Hedgehog : public Creature {
        public:
            Hedgehog(Environment * const room, std::string const & name);
            ~Hedgehog() override = default;

            std::string action() override;
            std::string fight(Actor * const character) override;
    };

    class Dragon : public Creature {
        private:
            Direction curr_dir;
        public:
            Dragon(Environment * const room, std::string const & name);
            ~Dragon() override = default;

            std::string action() override;
            std::string fight(Actor * const character) override;
    };

    class Worg : public Creature {
        public:
            Worg(Environment * const room, std::string const & name);
            ~Worg() override = default;

            std::string action() override;
            std::string fight(Actor * const character) override;
    };

    class Humanoid : public Actor {
        public:
            Humanoid(int const health, int const attack_damage,
                     Environment * const room, std::string const & type,
                     std::string const & name);
            ~Humanoid() override = default;
    };

    class Demon : public Humanoid {
        public:
            Demon(Environment * const room, std::string const & name);
            ~Demon() override = default;

            std::string action() override;
            std::string fight(Actor * const character) override;
    };

    class Goblin : public Humanoid {
        public:
            Goblin(Environment * const room, std::string const & name);
            ~Goblin() override = default;

            std::string action() override;
            std::string fight(Actor * const character) override;
    };

    class Zombie : public Humanoid {
        public:
            Zombie(Environment * const room, std::string const & name);
            ~Zombie() override = default;

            std::string action() override;
            std::string fight(Actor * const character) override;
    };
}
