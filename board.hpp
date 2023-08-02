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

        node *startNode;

        node *endNode;

        vector <vector <node *>> lookupMatrix;

        string selectedAlgo;
    
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

        node * getStartNode();

        void setStartNode(node * newNode);

        node * getEndNode();

        void setEndNode(node * newNode);

        void createNodeLookupMatrix();

        vector <vector <node *>> getLookupMatrix();

        void printLookup();

        void setSelectedAlgo(string newAlgo);

        string getSelectedAlgo();

};

node *makeNodeColumn(int columnLen, int xVal, int newNodeSize);

void mergeColumns(vector <node*> listColumnHeads);