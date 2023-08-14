#include "UIclass.hpp"
#include <iostream>

UIelements::UIelements(board * newBoard, SDL_Renderer * newRenderer, SDL_Window * newWindow, int newWIDTH, int newHEIGHT){
    curBoard = newBoard;
    renderer = newRenderer;
    window = newWindow;
    UIstate = "render_board_main_menu";
    WIDTH = newWIDTH;
    HEIGHT = newHEIGHT;

    int curY = 0;
    int buttonSize = 60;

    mainButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "set_start_end"));
    curY += buttonSize;

    mainButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "select_algo"));
    curY += buttonSize;

    mainButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "select_bfs"));
    curY += buttonSize;

    mainButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "select_dfs"));
    curY += buttonSize;

    mainButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "select_dijkstra"));
    curY += buttonSize;

    mainButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "select_A_star"));
    curY += buttonSize;

    mainButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "blank1"));
    curY += buttonSize;

    mainButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "obstacles"));
    curY += buttonSize;

    mainButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "blank2"));
    curY += buttonSize;

    mainButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "blank3"));
    curY += buttonSize;

    mainButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "start"));
    curY += buttonSize;

    mainButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "clear_path"));
    curY += buttonSize;


    curY = 0;

    obstacleButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "start_set_obstacles"));
    curY += buttonSize;

    obstacleButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "stop_set_obstacles"));
    curY += buttonSize;

    obstacleButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "erase_obstacles"));
    curY += buttonSize;

    obstacleButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "Algo_1"));
    curY += buttonSize;

    obstacleButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "Algo_2"));
    curY += buttonSize;

    obstacleButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "Algo_3"));
    curY += buttonSize;

    obstacleButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "set_random_obstacles"));
    curY += buttonSize;

    obstacleButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "clear_obstacles"));
    curY += buttonSize;

    obstacleButtonList.push_back(Button(curBoard->getWidthInPx(), curY, WIDTH, curY + buttonSize, "go_back"));
    curY += buttonSize;

}

Button::Button(int newx1, int newy1, int newx2, int newy2, string newButtonType){
    x1 = newx1;
    y1 = newy1;

    x2 = newx2;
    y2 = newy2;

    buttonType = newButtonType;

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

void UIelements::checkBoardClick(){
    SDL_Event event;
    
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_MOUSEBUTTONDOWN){
            int x = event.button.x;
            int y = event.button.y;
            if (x <= curBoard->getWidthInPx() && y <= curBoard->getHeightInPx()){
                // cout << "this worked" << endl;
                // cout << clickedNode(x,y)->getInFinalPath() << endl;
                // clickedNode(x,y)->setInFinalPath(true);
                if (UIstate == "set_start_node"){
                    if (clickedNode(x,y)->getTraversable() == true){
                        curBoard->setStartNode(clickedNode(x,y));
                        UIstate = "set_end_node";
                    }
                }
                else if (UIstate == "set_end_node"){
                    if (clickedNode(x,y)->getTraversable() == true){
                        curBoard->setEndNode(clickedNode(x,y));
                        UIstate = "render_board_main_menu";
                    }
                }
                else if (UIstate == "start_set_obstacles"){
                    clickedNode(x,y)->setTraversable(false);
                }
                else if (UIstate == "erase_obstacles"){
                    clickedNode(x,y)->setTraversable(true);
                }
            }
        }
        else if (event.type == SDL_MOUSEMOTION && (event.motion.state & SDL_BUTTON_LMASK)){
            if (UIstate == "start_set_obstacles"){
                int x = event.motion.x;
                int y = event.motion.y;
                if (x <= curBoard->getWidthInPx() && y <= curBoard->getHeightInPx()) {
                    clickedNode(x, y)->setTraversable(false);
                }
            }
            else if (UIstate == "erase_obstacles"){
                int x = event.motion.x;
                int y = event.motion.y;
                if (x <= curBoard->getWidthInPx() && y <= curBoard->getHeightInPx()) {
                    clickedNode(x, y)->setTraversable(true);
                }
            }
        // break;
        }
    }
}

void UIelements::renderAll(){
    // bug with this 
    // SDL_RenderClear(renderer);
    drawBoard();
    // if (UIstate == "start_select"){
    //     checkBoardClick("select_start_node");
    //     checkExitClick();
    // }
    // if set start is clicked
    // cout << UIstate << endl;
    if (UIstate == "set_start_node"){
        checkBoardClick();
        drawMainMenu();
    }
    else if (UIstate == "set_end_node"){
        checkBoardClick();
        drawMainMenu();
    }
    else if (UIstate == "render_board_main_menu"){
        checkMainMenuButtonClick();
        drawMainMenu();
    }
    else if (UIstate == "render_board_obstacle_menu"){
        checkObstacleMenuButtonClick();
        drawObstacleMenu();
    }
    else if (UIstate == "start_set_obstacles"){
        checkBoardClick();
        drawObstacleMenu();
        checkObstacleMenuButtonClick();
    }
    else if (UIstate == "erase_obstacles"){
        checkBoardClick();
        drawObstacleMenu();
        checkObstacleMenuButtonClick();
    }
    // cout << UIstate << endl;
}

node * UIelements::clickedNode(int x, int y){
    int xIndex = ceil(x / curBoard->getNodeSize());
    int yIndex = ceil(y / curBoard->getNodeSize());

    vector <vector <node *>> curLookupMatrix = curBoard->getLookupMatrix();
    node *clickedNode = curLookupMatrix[yIndex][xIndex];
    return clickedNode;
}

void UIelements::setUIstate(string newUIstate){
    UIstate = newUIstate;
}

string UIelements::getUIstate(){
    return UIstate;
}

void UIelements::checkExitClick(){

}

void UIelements::checkMainMenuButtonClick(){
    SDL_Event event;

    while (SDL_PollEvent(&event)){
        Button * clickedButton = nullptr;
        if (event.type == SDL_MOUSEBUTTONDOWN){
            int x = event.button.x;
            int y = event.button.y;
            if (x > curBoard->getWidthInPx()){
                for(auto &thisButton: mainButtonList){
                    if (y > thisButton.y1 && y < thisButton.y2){
                        clickedButton = &thisButton;
                        cout << "button Cliicked" << endl;
                        break;
                    }
                }
                
            }
        }
        if (clickedButton == nullptr){
            break;
        }
        if (clickedButton->buttonType == "set_start_end"){
            UIstate = "set_start_node";
            cout << UIstate << endl;
        } 
        else if (clickedButton->buttonType == "select_bfs"){
            curBoard->setSelectedAlgo("bfs");
        } 
        else if (clickedButton->buttonType == "select_dfs"){
            curBoard->setSelectedAlgo("dfs");
        } 
        else if (clickedButton->buttonType == "select_dijkstra"){
            curBoard->setSelectedAlgo("dijkstra");
        } 
        else if (clickedButton->buttonType == "select_A_star"){
            curBoard->setSelectedAlgo("A_star");
        } 
        else if (clickedButton->buttonType == "blank1"){
            // Handle the action for the "blank1" button type
        } 
        else if (clickedButton->buttonType == "obstacles"){
            UIstate = "render_board_obstacle_menu";
        } 
        else if (clickedButton->buttonType == "blank2"){
            // Handle the action for the "blank2" button type
        } 
        else if (clickedButton->buttonType == "blank3"){
            // Handle the action for the "blank3" button type
        } 
        else if (clickedButton->buttonType == "start"){
            // Handle the action for the "start" button type
            if (curBoard->getSelectedAlgo() == ""){
                break;
            }
            else{
                curBoard->setRunAlgo(true);
            }
        } 
        else if (clickedButton->buttonType == "clear_path"){
            curBoard->clearPath();
        }
        cout << clickedButton->buttonType <<endl;
        // break;
    }
}

void UIelements::checkObstacleMenuButtonClick(){
    SDL_Event event;

    while (SDL_PollEvent(&event)){
        Button * clickedButton = nullptr;
        if (event.type == SDL_MOUSEBUTTONDOWN){
            int x = event.button.x;
            int y = event.button.y;
            if (x > curBoard->getWidthInPx()){
                for(auto &thisButton: obstacleButtonList){
                    if (y > thisButton.y1 && y < thisButton.y2){
                        clickedButton = &thisButton;
                        cout << "button Cliicked" << endl;
                        break;
                    }
                }
                
            }
        }
        if (clickedButton == nullptr){
            break;
        }
        if (clickedButton->buttonType == "start_set_obstacles"){
            UIstate = "start_set_obstacles";
            cout << UIstate << endl;
        } 
        else if (clickedButton->buttonType == "stop_set_obstacles"){
            UIstate = "render_board_obstacle_menu";
        } 
        else if (clickedButton->buttonType == "erase_obstacles"){
            UIstate = "erase_obstacles";
        } 
        else if (clickedButton->buttonType == "Algo_1"){

        } 
        else if (clickedButton->buttonType == "Algo_2"){

        } 
        else if (clickedButton->buttonType == "Algo_3"){
            // Handle the action for the "blank1" button type
        } 
        else if (clickedButton->buttonType == "set_random_obstacles"){
            curBoard->createRandomObstacles();
        } 
        else if (clickedButton->buttonType == "clear_obstacles"){
            // Handle the action for the "blank2" button type
            curBoard->clearObstacles();
        } 
        else if (clickedButton->buttonType == "go_back"){
            // Handle the action for the "blank3" button type
            UIstate = "render_board_main_menu";
        }
        cout << clickedButton->buttonType <<endl;
        // break;
    }
}

void UIelements::drawMainMenu(){
    for (auto &curButton : mainButtonList){
        SDL_Rect curRect = {curButton.x1, curButton.y1, curButton.x2 - curButton.x1, curButton.y2 - curButton.y2};
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &curRect);
    }
    SDL_RenderPresent(renderer);
}

void UIelements::drawObstacleMenu(){
    for (auto &curButton : obstacleButtonList){
        SDL_Rect curRect = {curButton.x1, curButton.y1, curButton.x2 - curButton.x1, curButton.y2 - curButton.y2};
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderDrawRect(renderer, &curRect);
    }
    SDL_RenderPresent(renderer);
}