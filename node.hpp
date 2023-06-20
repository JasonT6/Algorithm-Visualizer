#include "x_y_position.hpp"

class node{

    private:
        node *north;
        node *east;
        node *south;
        node *west;

        bool traversable;

        bool visited;

        node *reachingNode;



};