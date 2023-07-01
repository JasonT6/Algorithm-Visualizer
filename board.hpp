#pragma once
#include <vector>
#include "node.hpp"

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

};

node *makeNodeColumn(int columnLen, int xVal, int newNodeSize);

void mergeColumns(vector <node*> listColumnHeads);