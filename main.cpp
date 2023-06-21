#include <iostream>
#include <vector>
#include "node.hpp"
#include "board.hpp"

using namespace std;

int main(){
    // TESTCODE
    // node head = node(nullptr, nullptr, nullptr, nullptr, new x_y_position(10, 10));
    // head.setNorth(new node(nullptr, nullptr, nullptr, nullptr, new x_y_position(20, 10)));
    // head.getNorth()->getNodePosition()->getX();
    // cout << head.getNorth()->getNodePosition()->getX() << endl;

    board currentBoard = board(5,3, 10);
    node *current = currentBoard.getHead();

    cout << "success" << endl;
    cout << nullptr << endl;
    cout << current << endl;
    cout << current->getSouth() << endl;
    cout << current->getSouth()->getSouth() << endl;
    cout << current->getSouth()->getSouth()->getSouth() << endl;
    cout << current->getSouth()->getSouth()->getSouth()->getSouth() << endl;

    

    cout << "hello" << endl;;
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