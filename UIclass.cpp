#include "UIclass.hpp"
#include <iostream>

UIelements::UIelements(board * newBoard, SDL_Renderer * newRenderer, SDL_Window * newWindow){
    curBoard = newBoard;
    renderer = newRenderer;
    window = newWindow;
}

board * UIelements::getCurBoard(){
    return curBoard;
}

string UIelements::getSelectedAlgorithm(){
    return selectedAlgorithm;
}

void UIelements::setAlgorithm(string newALgo){
    selectedAlgorithm = newALgo;
}

void UIelements::drawBoard(){
    
    node *curRow = curBoard->getHead();
    node *curMov = curRow;

    int nodeSize = curRow->getNodeSize();

    int initialX = 0;
    int initialY = 0;

    while(curRow != nullptr){
        curMov = curRow;
        while(curMov != nullptr){
            if(curMov->getTraversable() == false){
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            }
            else if (curMov == curBoard->getStartNode()){
                SDL_SetRenderDrawColor(renderer, 72, 126, 2, 255);
            }
            else if (curMov == curBoard->getEndNode()){
                SDL_SetRenderDrawColor(renderer, 202, 70, 72, 255);
            }
            else if(curMov->getInFinalPath()){
                SDL_SetRenderDrawColor(renderer, 0, 122, 204, 255);
            }
            else if (curMov->getVisited()){
                SDL_SetRenderDrawColor(renderer, 51, 51, 51, 255);
            }
            else{
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            }
            SDL_Rect rect = { initialX, initialY, nodeSize, nodeSize};
            SDL_RenderFillRect(renderer, &rect);
            initialX += nodeSize;
            curMov = curMov->getEast();
        }
        initialX = 0;
        initialY += nodeSize;
        curRow = curRow->getSouth();
    }

    SDL_RenderPresent(renderer);
}

void UIelements::checkClick(){
    SDL_Event event;
    
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_MOUSEBUTTONDOWN){
            int x = event.button.x;
            int y = event.button.y;
            if (x <= curBoard->getWidthInPx() && y <= curBoard->getHeightInPx()){
                // cout << "this worked" << endl;
                // cout << clickedNode(x,y)->getInFinalPath() << endl;
                // clickedNode(x,y)->setInFinalPath(true);
            }
        }
        break;
    }
}

void UIelements::renderAll(){
    drawBoard();
    checkClick();
}

node * UIelements::clickedNode(int x, int y){
    int xIndex = ceil(x / curBoard->getNodeSize());
    int yIndex = ceil(y / curBoard->getNodeSize());

    vector <vector <node *>> curLookupMatrix = curBoard->getLookupMatrix();
    node *clickedNode = curLookupMatrix[yIndex][xIndex];
    return clickedNode;
}