#pragma once
#include <iostream>
#include <vector>
#include "node.hpp"
#include "board.hpp"
#include "algorithms.hpp"
#include <SDL2/SDL.h>
#include <cmath>

class Button;

class UIelements{
    private:
        board *curBoard;

        int WIDTH;

        int HEIGHT;

        string selectedAlgorithm;

        SDL_Renderer *renderer;

        SDL_Window *window;
        
        // possible UIstates: set_start_node, set_end_node, render_board_main_menu, render_board_obstacle_menu
        string UIstate;

        vector <Button> mainButtonList;

        vector <Button> obstacleButtonList;

    public:

        UIelements(board * newBoard, SDL_Renderer * newRenderer, SDL_Window * newWindow, int newWIDTH, int newHEIGHT);

        board * getCurBoard();

        string getSelectedAlgorithm();

        void setAlgorithm(string newAlgo);

        void drawBoard();

        void checkBoardClick();

        void renderAll();

        node * clickedNode(int x, int y);

        void setUIstate(string newUIstate);

        string getUIstate();

        void checkExitClick();

        void checkMainMenuButtonClick();
        
        void checkObstacleMenuButtonClick();

        void drawMainMenu();

        void drawObstacleMenu();

};

class Button{
    public:
        int x1;
        int y1;
        int x2;
        int y2;
        string buttonType;

        Button(int newx1, int newy1, int newx2, int newy2, string newButtonType);
};