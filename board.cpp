#pragma once
#include "board.hpp"
using namespace std;

board::board(int newHeightInNodes, int newWidthInNodes, int newNodeSize){

    head = new node(nullptr, nullptr, nullptr, nullptr, new x_y_position(newNodeSize/2, newNodeSize/2));
    
    heightInNodes = newHeightInNodes;
    widthInNodes = newWidthInNodes;

    nodeSize = newNodeSize;

    heightInPx = heightInNodes * nodeSize;

    widthInPx = widthInNodes * nodeSize;

    node *curColumn = head;
    node *prevColumn = head;

    node *curRow = head;
    node *prevRow = head;

    int initialX = head->getNodePosition()->getX();
    int initialY = head->getNodePosition()->getY();

    // for(int col = 0; col < heightInNodes; col++){
        
    // }
    // cout << head << endl;
    for(int row = 0; row < widthInNodes - 1; row++){

        x_y_position newPos = x_y_position(initialX, initialY + nodeSize*row);
        node *newNode =  new node(prevRow, nullptr, nullptr, nullptr, &newPos);
        
        prevRow->setSouth(newNode);

        prevRow = prevRow->getSouth();
    }

}

node *board::getHead(){
    return head;
}