#pragma once


namespace text_adventure {
    class Object {
        private:
            int _volume;
            int _weight;
            bool _is_liquid;

        public:
            Object();

            virtual bool is_liquid() = 0;
            virtual int volume() = 0;
            virtual int weight() = 0;
    };

    class Container : public Object {
        public:
            Container();

            bool is_liquid() override;
            int volume() override;
            int weight() override;

            int add(const Object & object);
            int max_volume();
            int max_weight();
            int remove(const Object & object);
    };

    class Consumable : public Object {
        public:
            Consumable();

            bool is_liquid() override;
            int volume() override;
            int weight() override;
    };

    class Weapon : public Object {
        public:
            Weapon();

            bool is_liquid() override;
            int volume() override;
            int weight() override;
    };

    class Key : public Object {
        public:
            Key();

            bool is_liquid() override;
            int volume() override;
            int weight() override;
    };

    class Knapsack : public Container {
        public:
            Knapsack();

            bool is_liquid() override;
            int volume() override;
            int weight() override;
    };
}
