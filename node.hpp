#pragma once
#include "x_y_position.hpp"
#include <iostream>
#include <limits>

class node{

    private:
        node *north;
        node *east;
        node *south;
        node *west;

        bool traversable;

        bool visited;

        node *reachingNode;

        x_y_position *position;

        bool inFinalPath;

        int nodeSize;

        // for dijkstras and A*
        double distance;
    
    public:

        node(node *newNorth, node *newEast, node *newSouth, node *newWest, x_y_position *newPosition, int newSize);

        void setNorth(node *newNode);

        void setEast(node *newNode);

        void setSouth(node *newNode);

        void setWest(node *newNode);

        node * getNorth();

        node * getEast();

        node * getSouth();

        node * getWest();

        bool getTraversable();

        void setTraversable(bool trav);

        bool getVisited();

        void setVisited(bool visit);

        node * getReachingNode();

        void setReachingNode(node * newNode);

        x_y_position *getNodePosition();

        void setInFinalPath(bool setInFinalPath);

        bool getInFinalPath();

        int getNodeSize();

        void setNodeSize(int newSize);

        double getDistance();

        void setDistance(double newDist);

};

