#include "board.hpp"
#include <vector>
using namespace std;


board::board(int newHeightInNodes, int newWidthInNodes, int newNodeSize){
    
    heightInNodes = newHeightInNodes;
    widthInNodes = newWidthInNodes;

    nodeSize = newNodeSize;

    heightInPx = heightInNodes * nodeSize;

    widthInPx = widthInNodes * nodeSize;

    int initialX = newNodeSize/2;

    vector <node*> columnHeadList;

    for (int i = 0; i < newWidthInNodes; i++){
        node *newColumnHead = makeNodeColumn(newHeightInNodes, initialX, newNodeSize);
        columnHeadList.push_back(newColumnHead);
        initialX += newNodeSize;
    }

    mergeColumns(columnHeadList);

    head = columnHeadList[0];

    createNodeLookupMatrix();

    runAlgo = false;

    selectedAlgo = "bfs";

    printLookup();
   
}

node *board::getHead(){
    return head;
}

int board::getHeightInPx(){
    return heightInPx;
}

int board::getWidthInPx(){
    return widthInPx;
}

int board::getHeightInNodes(){
    return heightInNodes;
}

int board::getWidthInNodes(){
    return widthInNodes;
}

int board::getNodeSize(){
    return nodeSize;
}


node *makeNodeColumn(int columnLen, int xVal, int newNodeSize){

    x_y_position *newPos = new x_y_position(xVal, newNodeSize/2);
    node *head = new node(nullptr, nullptr, nullptr, nullptr, newPos, newNodeSize);

    node *cur = head;
    for (int i = 0; i < columnLen - 1; i++){
        x_y_position *Pos = new x_y_position(xVal, newNodeSize/2 + i * newNodeSize);
        node * newNode = new node(cur,nullptr, nullptr, nullptr, Pos, newNodeSize);
        cur->setSouth(newNode);
        cur = newNode;
    }

    return head;
}

void mergeColumns(vector <node*> listColumnHeads){

    if (listColumnHeads.size() < 2){
        return;
    }

    int prevIndex = 0;
    while(prevIndex < (int)listColumnHeads.size() - 1){
        node *prevMoving = listColumnHeads[prevIndex];
        node *curMoving = listColumnHeads[prevIndex + 1];

        while(curMoving != nullptr){

            prevMoving->setEast(curMoving);
            curMoving->setWest(prevMoving);

            prevMoving = prevMoving->getSouth();
            curMoving = curMoving->getSouth();
        }
        prevIndex++;

    }

}

void board::printBoard(){
    cout << "___________________________________" << endl;
    cout << endl;

    node *curRow = head;
    node *curMov = curRow;

    while(curRow != nullptr){
        curMov = curRow;
        while(curMov != nullptr){
            if(curMov->getTraversable() == false){
                cout << "# ";
            }
            else if(curMov->getInFinalPath()){
                cout << "o ";
            }
            else if (curMov->getVisited()){
                cout << ". ";
                // cout << curMov->getDistance() << " ";
            }
            else{
                cout << "  ";
            }
            curMov = curMov->getEast();
        }
        cout << endl;
        curRow = curRow->getSouth();
    }

    cout << "___________________________________" << endl;

    
    // cout << "___________________________________" << endl;
    // cout << endl;

    // node *curRow2 = head;
    // node *curMov2 = curRow2;

    // while(curRow2 != nullptr){
    //     curMov2 = curRow2;
    //     while(curMov2 != nullptr){
    //         cout << curMov2 << " "; 
    //         curMov2 = curMov2->getEast();
    //     }
    //     cout << endl;
    //     curRow2 = curRow2->getSouth();
    // }

    // cout << "___________________________________" << endl;
}

void board::createRandomObstacles(){
    
    node *curRow = head;
    node *curMov = curRow;

    srand(time(NULL));

    while(curRow != nullptr){
        curMov = curRow;
        while(curMov != nullptr){
            int randomNumber;
            randomNumber = rand();
            if (randomNumber % 4 == 0){
                curMov->setTraversable(false);
            }
            curMov = curMov->getEast();
        }
        curRow = curRow->getSouth();
    }
}

void board::clearPath(){

    node *curRow = head;
    node *curMov = curRow;

    while(curRow != nullptr){
        curMov = curRow;
        while(curMov != nullptr){
            curMov->setVisited(false);
            curMov->setReachingNode(nullptr);
            curMov->setDistance(numeric_limits<int>::max());
            curMov->setInFinalPath(false);
            curMov = curMov->getEast();
        }
        curRow = curRow->getSouth();
    }
}

node * board::getStartNode(){
    return startNode;
}   

void board::setStartNode(node * newNode){
    startNode = newNode;
}

node * board::getEndNode(){
    return endNode;
}   

void board::setEndNode(node * newNode){
    endNode = newNode;
}

void board::createNodeLookupMatrix(){
    node * curRow = head;
    node * curCol = head;

    vector <vector <node *>> newlookupMatrix;

    while(curRow != nullptr){
        
        vector <node *> curColVec;

        while(curCol != nullptr){
            curColVec.push_back(curCol);
            curCol = curCol->getEast();
        }
        newlookupMatrix.push_back(curColVec);
        curRow = curRow->getSouth();
        curCol = curRow;
    }

    lookupMatrix = newlookupMatrix;

}

vector <vector <node *>> board::getLookupMatrix(){
    return lookupMatrix;
}

//for debugging
void board::printLookup(){
    cout << "did it get here" << endl;
    for (int i = 0; i < lookupMatrix.size(); ++i) {
        for (int j = 0; j < lookupMatrix[i].size(); ++j) {
            cout << lookupMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void board::setSelectedAlgo(string newAlgo){
    selectedAlgo = newAlgo;
}

string board::getSelectedAlgo(){
    return selectedAlgo;
}

void board::setRunAlgo(bool set){
    runAlgo = set;
}

bool board::getRunAlgo(){
    return runAlgo;
}

void board::clearObstacles(){
    for (int i = 0; i < lookupMatrix.size(); i++){
        for (int j = 0; j < lookupMatrix[i].size(); j++){
            lookupMatrix[i][j]->setTraversable(true);
        }
    }
}