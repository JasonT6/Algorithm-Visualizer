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

void node::setNorth(node *newNode){
    north = newNode;
}

void node::setEast(node *newNode){
    east = newNode;
}

void node::setSouth(node *newNode){
    south = newNode;
}

void node::setWest(node *newNode){
    west = newNode;
}


node * node::getNorth(){
    return north;
}

node * node::getEast(){
    return east;
}

node * node::getSouth(){
    return south;
}

node * node::getWest(){
    return west;
}

bool node::getTraversable(){
    return traversable;
}

void node::setTraversable(bool trav){
    traversable = trav;
    return;
}

bool node::getVisited(){
    return visited;
}

void node::setVisited(bool visit){
    visited = visit;
    return;
}

node * node::getReachingNode(){
    return reachingNode;
}

void node::setReachingNode(node * newNode){
    reachingNode = newNode;
    return;
}

x_y_position *node::getNodePosition(){
    return position;
}
