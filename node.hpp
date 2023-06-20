#include "x_y_position.hpp"

class node{

    public:
        node *north;
        node *east;
        node *south;
        node *west;

        bool traversable;

        bool visited;

        node *reachingNode;

        x_y_position *position;

        node(node *newNorth, node *newEast, node *newSouth, node *newWest, x_y_position *newPosition);
        

};