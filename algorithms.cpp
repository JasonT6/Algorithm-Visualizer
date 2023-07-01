#include "algorithms.hpp"

bool bfs(node *start, node *end){
    cout << "bfs Started" << endl;
    list <node *> wavefront;
    wavefront.push_back(start);

    while (wavefront.empty() == false){
        node * curNode = wavefront.front();
        wavefront.pop_front();

        if (curNode->getVisited()){
            continue;
        }

        curNode->setVisited(true);

        if (curNode == end){
            cout << "bfs success" << endl; 
            return true;
        }

        if (curNode->getNorth() != nullptr && curNode->getNorth()->getReachingNode() == nullptr && curNode->getNorth()->getTraversable()){
            curNode->getNorth()->setReachingNode(curNode);
            wavefront.push_back(curNode->getNorth());
        }

        if (curNode->getEast() != nullptr && curNode->getEast()->getReachingNode() == nullptr && curNode->getEast()->getTraversable()){
            curNode->getEast()->setReachingNode(curNode);
            wavefront.push_back(curNode->getEast());
        }

        if (curNode->getSouth() != nullptr && curNode->getSouth()->getReachingNode() == nullptr && curNode->getSouth()->getTraversable()){
            curNode->getSouth()->setReachingNode(curNode);
            wavefront.push_back(curNode->getSouth());
        }

        if (curNode->getWest() != nullptr && curNode->getWest()->getReachingNode() == nullptr && curNode->getWest()->getTraversable()){
            curNode->getWest()->setReachingNode(curNode);
            wavefront.push_back(curNode->getWest());
        }
    }

    cout << "bfs fail" << endl;
    return false;
}


void bfsTraceback(node *start, node *end){
    cout << "traceback started" << endl;
    node *curNode = end;
    while (curNode != start){
        cout << curNode << endl;
        curNode->setInFinalPath(true);
        curNode = curNode->getReachingNode();
    }

    cout << "traceback success" << endl;
}