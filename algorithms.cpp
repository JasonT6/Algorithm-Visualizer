#include "algorithms.hpp"

bool bfs(UIelements *curUI, node *start, node *end){
    cout << "bfs Started" << endl;
    list <node *> wavefront;
    wavefront.push_back(start);

    while (wavefront.empty() == false){
        curUI->renderAll();

        SDL_Event windowEvent;
        if (SDL_PollEvent(&windowEvent)){
            if (SDL_QUIT == windowEvent.type){
                break;
            }
        }

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
    int count = 0;
    node *curNode = end;
    while (curNode != start){
        cout << curNode << endl;
        curNode->setInFinalPath(true);
        curNode = curNode->getReachingNode();
        count++;
    }


    cout << "traceback done" << endl;
    cout << "score" << count << endl;
}


bool dfs_recursive(UIelements *curUI, node *start, node *end){
    // cout << "dfs_recursive started" << endl;
    
    SDL_Delay(1);
    curUI->renderAll();

    SDL_Event windowEvent;
    if (SDL_PollEvent(&windowEvent)){
        if (SDL_QUIT == windowEvent.type){
            // needs to return true to stop the loop but then it thinks it was successful when it actually was not
            return true;
        }
    }

    if (start == end){
        cout << "dfs_recursive success" << endl;
        return true;
    }

    start->setVisited(true);

    if (start->getNorth() != nullptr && start->getNorth()->getReachingNode() == nullptr && start->getNorth()->getTraversable()){
            start->getNorth()->setReachingNode(start);
            start = start->getNorth();
            if (dfs_recursive(curUI, start, end)){
                return true;
            }
        }

    if (start->getEast() != nullptr && start->getEast()->getReachingNode() == nullptr && start->getEast()->getTraversable()){
        start->getEast()->setReachingNode(start);
        start = start->getEast();
        if (dfs_recursive(curUI, start, end)){
            return true;
        }
    }

    if (start->getSouth() != nullptr && start->getSouth()->getReachingNode() == nullptr && start->getSouth()->getTraversable()){
        start->getSouth()->setReachingNode(start);
        start = start->getSouth();
        if (dfs_recursive(curUI, start, end)){
            return true;
        }
    }

    if (start->getWest() != nullptr && start->getWest()->getReachingNode() == nullptr && start->getWest()->getTraversable()){
        start->getWest()->setReachingNode(start);
        start = start->getWest();
        if (dfs_recursive(curUI, start, end)){
            return true;
        }
    }
    
    return false;
}

bool dfs_with_stack(UIelements *curUI, node *start, node *end){
    cout << "dfs_with_stack Started" << endl;
    if (start->getTraversable() == false || end->getTraversable() == false){
        cout << "dijkstra fail" << endl;
        return false;
    }
    list <node *> stack;
    stack.push_back(start);

    while (stack.empty() == false){
        SDL_Delay(1);
        curUI->renderAll();

        SDL_Event windowEvent;
        if (SDL_PollEvent(&windowEvent)){
            if (SDL_QUIT == windowEvent.type){
                break;
            }
        }
        
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

bool dijkstra(UIelements *curUI, node *start, node *end){
    cout << "dijkstra Started" << endl;

    if (start->getTraversable() == false || end->getTraversable() == false){
        cout << "dijkstra fail" << endl;
        return false;
    }

    priority_queue<pair<double, node*>, vector<pair<double, node*>>, greater<pair<double, node*>>> wavefront;
    start->setDistance(0);
    double startDistance = start->getDistance();
    wavefront.push({startDistance, start});

    while (wavefront.empty() == false){
        SDL_Delay(1);
        curUI->renderAll();

        SDL_Event windowEvent;
        if (SDL_PollEvent(&windowEvent)){
            if (SDL_QUIT == windowEvent.type){
                break;
            }
        }
        
        node * curNode = wavefront.top().second;
        wavefront.pop();

        if (curNode->getVisited()){
            continue;
        }

        curNode->setVisited(true);

        if (curNode == end){
            cout << "dijkstra success" << endl; 
            return true;
        }

        if (curNode->getNorth() != nullptr && curNode->getNorth()->getVisited() == false && curNode->getNorth()->getTraversable()){
            double newDist = curNode->getDistance() + curNode->getNodeSize();
            if (newDist < curNode->getNorth()->getDistance()){
                curNode->getNorth()->setReachingNode(curNode);
                curNode->getNorth()->setDistance(newDist);
                wavefront.push({newDist,curNode->getNorth()});
            }
            
        }

        if (curNode->getEast() != nullptr && curNode->getEast()->getVisited() == false && curNode->getEast()->getTraversable()){
            double newDist = curNode->getDistance() + curNode->getNodeSize();
            if (newDist < curNode->getEast()->getDistance()){
                curNode->getEast()->setReachingNode(curNode);
                curNode->getEast()->setDistance(newDist);
                wavefront.push({newDist,curNode->getEast()});
            }
        }

        if (curNode->getSouth() != nullptr && curNode->getSouth()->getVisited() == false && curNode->getSouth()->getTraversable()){
            double newDist = curNode->getDistance() + curNode->getNodeSize();
            if (newDist < curNode->getSouth()->getDistance()){
                curNode->getSouth()->setReachingNode(curNode);
                curNode->getSouth()->setDistance(newDist);
                wavefront.push({newDist,curNode->getSouth()});
            }
        }

        if (curNode->getWest() != nullptr && curNode->getWest()->getVisited() == false && curNode->getWest()->getTraversable()){
            double newDist = curNode->getDistance() + curNode->getNodeSize();
            if (newDist < curNode->getWest()->getDistance()){
                curNode->getWest()->setReachingNode(curNode);
                curNode->getWest()->setDistance(newDist);
                wavefront.push({newDist,curNode->getWest()});
            }
        }
    }

    cout << "dijkstra fail" << endl;
    return false;
}