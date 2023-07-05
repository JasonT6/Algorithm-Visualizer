#pragma once
#include <vector>
#include "node.hpp"
#include <time.h>
#include <limits>

using namespace std;

class board{

    private:

        node *head;

        int heightInPx;

        int widthInPx;

        int heightInNodes;

        int widthInNodes;

        int nodeSize;
    
    public:

        board(int newHeightInNodes, int newWidthInNodes, int newNodeSize);

        node * getHead();

        int getHeightInPx();

        int getWidthInPx();

        int getHeightInNodes();

        int getWidthInNodes();

        int getNodeSize();

        void printBoard();

        void createRandomObstacles();

        void clearPath();

};

node *makeNodeColumn(int columnLen, int xVal, int newNodeSize);

void mergeColumns(vector <node*> listColumnHeads);