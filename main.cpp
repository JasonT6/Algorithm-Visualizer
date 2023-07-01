#include <iostream>
#include <vector>
#include "node.hpp"
#include "board.hpp"
#include "algorithms.hpp"

using namespace std;

int main(){
    // TESTCODE
    // node head = node(nullptr, nullptr, nullptr, nullptr, new x_y_position(10, 10));
    // head.setNorth(new node(nullptr, nullptr, nullptr, nullptr, new x_y_position(20, 10)));
    // head.getNorth()->getNodePosition()->getX();
    // cout << head.getNorth()->getNodePosition()->getX() << endl;

    board currentBoard = board(6,10, 10);
    // node *current = currentBoard.getHead();
    node *current = currentBoard.getHead();
    cout << current->getNodePosition()->getX() << endl;

    cout << "success" << endl;

    currentBoard.printBoard();

    current->setTraversable(false);

    currentBoard.printBoard();

    node * start = current->getEast();

    while (current->getEast() != nullptr){
        current = current->getEast();
    }

    node *end = current->getSouth();

    cout << "start" << start << endl;

    cout << "end: " << end << endl;

    current = currentBoard.getHead();
    for (int i = 0; i < 5; i++){
        current = current->getEast();
    }

    for (int i = 0; i < 4; i++){
        current->setTraversable(false);
        current = current->getSouth();
    }

    bfs(start, end);

    bfsTraceback(start, end);

    cout << "donehere" << endl;

    currentBoard.printBoard();

    cout << "success" << endl;







    // cout << current << endl;
    // cout << current->getSouth()->getNodePosition()->getY() << endl;
    // cout << current->getSouth()->getSouth()->getNodePosition()->getY() << endl;
    // cout << current->getSouth()->getSouth()->getSouth()->getNodePosition()->getY() << endl;
    // cout << current->getSouth()->getSouth()->getSouth()->getSouth()->getNodePosition()->getY() << endl;

    // cout << current << endl;
    // cout << current->getSouth() << endl;
    // cout << current->getSouth()->getSouth()<< endl;
    // cout << current->getSouth()->getSouth()->getSouth() << endl;
    // cout << current->getSouth()->getSouth()->getSouth()->getSouth()<< endl;

    // current = current->getSouth()->getSouth()->getSouth()->getSouth();
    
    // cout << "swap" << endl;

    // cout << current->getNorth()->getNodePosition()->getY() << endl;
    // cout << current->getNorth()->getNorth()->getNodePosition()->getY() << endl;
    // cout << current->getNorth()->getNorth()->getNorth()->getNodePosition()->getY() << endl;
    // cout << current->getNorth()->getNorth()->getNorth()->getNorth()->getNodePosition()->getY() << endl;

    // cout << current << endl;
    // cout << current->getNorth() << endl;
    // cout << current->getNorth()->getNorth() << endl;
    // cout << current->getNorth()->getNorth()->getNorth() << endl;
    // cout << current->getNorth()->getNorth()->getNorth()->getNorth() << endl;


    // cout << "go east" << endl;

    // cout << current->getNodePosition()->getX() << endl;
    // cout << current->getEast()->getNodePosition()->getX() << endl;
    // cout << current->getEast()->getEast()->getNodePosition()->getX() << endl;
    // // cout << current->getEast()->getEast()->getEast()->getNodePosition()->getX() << endl;

    // current = current->getEast()->getEast();

    // cout << current->getNodePosition()->getX() << endl;
    // cout << current->getWest()->getNodePosition()->getX() << endl;
    // cout << current->getWest()->getWest()->getNodePosition()->getX() << endl;

    // int count = 0;
    // while (current != nullptr){
    //     cout << current << endl;
    //     cout << count << endl;
    //     count++;
    //     current = current->getSouth();
    // }
    // cout << count;

    return 0;
}