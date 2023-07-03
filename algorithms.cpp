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


void Traceback(node *start, node *end){
    cout << "traceback started" << endl;
    node *curNode = end;
    while (curNode != start){
        cout << curNode << endl;
        curNode->setInFinalPath(true);
        curNode = curNode->getReachingNode();
    }

    cout << "traceback done" << endl;
}


bool dfs_recursive(node *start, node *end){
    cout << "dfs_recursive started" << endl;
    if (start == end){
        cout << "dfs_recursive success" << endl;
        return true;
    }

    if (start->getNorth() != nullptr && start->getNorth()->getReachingNode() == nullptr && start->getNorth()->getTraversable()){
            start->getNorth()->setReachingNode(start);
            start = start->getNorth();
            if (dfs_recursive(start, end)){
                return true;
            }
        }

    if (start->getEast() != nullptr && start->getEast()->getReachingNode() == nullptr && start->getEast()->getTraversable()){
        start->getEast()->setReachingNode(start);
        start = start->getEast();
        if (dfs_recursive(start, end)){
            return true;
        }
    }

    if (start->getSouth() != nullptr && start->getSouth()->getReachingNode() == nullptr && start->getSouth()->getTraversable()){
        start->getSouth()->setReachingNode(start);
        start = start->getSouth();
        if (dfs_recursive(start, end)){
            return true;
        }
    }

    if (start->getWest() != nullptr && start->getWest()->getReachingNode() == nullptr && start->getWest()->getTraversable()){
        start->getWest()->setReachingNode(start);
        start = start->getWest();
        if (dfs_recursive(start, end)){
            return true;
        }
    }
    
    return false;
}

bool dfs_with_stack(node *start, node *end){
    cout << "dfs_with_stack Started" << endl;
    list <node *> stack;
    stack.push_back(start);

    while (stack.empty() == false){
        node * curNode = stack.back();
        stack.pop_back();
        cout << "traversing: " << curNode << endl;

        if (curNode->getVisited()){
            continue;
        }

        curNode->setVisited(true);

        if (curNode == end){
            cout << "dfs_with_stack success" << endl; 
            return true;
        }

        if (curNode->getNorth() != nullptr && curNode->getNorth()->getReachingNode() == nullptr && curNode->getNorth()->getTraversable()){
            curNode->getNorth()->setReachingNode(curNode);
            stack.push_back(curNode->getNorth());
        }

        if (curNode->getEast() != nullptr && curNode->getEast()->getReachingNode() == nullptr && curNode->getEast()->getTraversable()){
            curNode->getEast()->setReachingNode(curNode);
            stack.push_back(curNode->getEast());
        }

        if (curNode->getSouth() != nullptr && curNode->getSouth()->getReachingNode() == nullptr && curNode->getSouth()->getTraversable()){
            curNode->getSouth()->setReachingNode(curNode);
            stack.push_back(curNode->getSouth());
        }

        if (curNode->getWest() != nullptr && curNode->getWest()->getReachingNode() == nullptr && curNode->getWest()->getTraversable()){
            curNode->getWest()->setReachingNode(curNode);
            stack.push_back(curNode->getWest());
        }
    }

    cout << "dfs_with_stack fail" << endl;
    return false;
}