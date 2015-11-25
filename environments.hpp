#include <string>


namespace text_adventure {
    enum Direction {NORTH, EAST, SOUTH, WEST};

    class Environment {
        private:
            vector<Actor> actors;
            vector<Object> objects;
            vector<Environment> neighbours;

        public:
            std::string description();
            virtual std::string type() = 0;
            virtual vector<Direction> directions();
            virtual Environment neighbour(const Direction dir);
            virtual void enter(const Actor & character);
            virtual void exit(const Actor & character);
            virtual void pick_up(const Object & object);
            virtual void drop(const Object & object);
    };

    class Outdoor : public Environment {
        virtual void weather();
    };

    class Forest : public Outdoor {
    };
}
