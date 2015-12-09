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
            bool _invincible;
            Environment * _room;
            std::string _type;
            std::string _name;

        public:
            Actor(int const health, int const attack_damage,
                  Environment * const room, std::string const type,
                  std::string const name);
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
        protected:
            Object * _hand;
            Container * _back;

        public:
            Human(int const health, int const attack_damage,
                  Environment * const room, std::string const type,
                  std::string const name);
            ~Human() override = default;

            /**
             * Helper function to update stats from consumable.
             */
            void consume_object(Object * const object);
            /**
             * Try to consume the given consumable.
             * Return false if it is not in inventory.
             */
            virtual bool consume(const std::string & consumable);

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
            std::string items();

            void go(const Direction direction) override;
            void action() override;
    };

    class Warrior : public Human {
        public:
            Warrior(Environment * const room, std::string const name);
            ~Warrior() override = default;

            void action() override;
            void fight(Actor * const character) override;
    };

    class Wizard : public Human {
        private:
            int _mana;

        public:
            Wizard(Environment * const room, std::string const name);
            ~Wizard() override = default;

            void action() override;
            void fight(Actor * const character) override;
            bool consume(const std::string & consumable) override;
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
            Creature(int const health, int const attack_damage,
                     Environment * const room, std::string const type,
                     std::string const name);
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
        private:
            Direction curr_dir;
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
            Humanoid(int const health, int const attack_damage,
                     Environment * const room, std::string const type,
                     std::string const name);
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
