#pragma once
#include <iostream>
#include <vector>
#include "node.hpp"
#include "board.hpp"
#include "algorithms.hpp"
#include <SDL2/SDL.h>
#include <cmath>

class UIelements{
    private:
        board *curBoard;

        string selectedAlgorithm;

        SDL_Renderer *renderer;

        SDL_Window *window;

    public:

        UIelements(board * newBoard, SDL_Renderer * newRenderer, SDL_Window * newWindow);

        board * getCurBoard();

        string getSelectedAlgorithm();

        void setAlgorithm(string newAlgo);

        void drawBoard();

        void checkClick();

        void renderAll();

        node * clickedNode(int x, int y);

};