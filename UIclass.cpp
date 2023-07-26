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

    int initialX = 0;
    int initialY = 0;

    while(curRow != nullptr){
        curMov = curRow;
        while(curMov != nullptr){
            if(curMov->getTraversable() == false){
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
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
            SDL_Rect rect = { initialX, initialY, 5, 5};
            SDL_RenderFillRect(renderer, &rect);
            initialX += 5;
            curMov = curMov->getEast();
        }
        initialX = 0;
        initialY += 5;
        curRow = curRow->getSouth();
    }

    SDL_RenderPresent(renderer);
}