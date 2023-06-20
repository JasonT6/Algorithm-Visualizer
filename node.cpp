#include "node.hpp"
using namespace std;

node::node(node *newNorth, node *newEast, node *newSouth, node *newWest, x_y_position *newPosition){
    north = newNorth;
    east = newEast;
    south = newSouth;
    west = newWest;

    traversable = false;

    visited = false;

    reachingNode = nullptr;

    position = newPosition;

}