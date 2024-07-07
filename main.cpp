#include <iostream>
#include <vector>
#include "node.hpp"
#include "board.hpp"
#include "algorithms.hpp"
#include "UIclass.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <thread>

using namespace std;

const int WIDTH = 1200, HEIGHT = 800;

void inputListener(UIelements* newUI){
    
    while(1){

        newUI->checkExitClick();
        
        if (newUI->getUIstate() == "set_start_node"){
            newUI->checkBoardClick();
        }
        else if (newUI->getUIstate() == "set_end_node"){
            newUI->checkBoardClick();
        }
        else if (newUI->getUIstate() == "render_board_main_menu"){
            newUI->checkMainMenuButtonClick();
        }
        else if (newUI->getUIstate() == "render_board_obstacle_menu"){
            newUI->checkObstacleMenuButtonClick();
        }
        else if (newUI->getUIstate() == "start_set_obstacles"){
            newUI->checkBoardClick();
            newUI->checkObstacleMenuButtonClick();
            
        }
        else if (newUI->getUIstate() == "erase_obstacles"){
            newUI->checkBoardClick();
            newUI->checkObstacleMenuButtonClick();
        }
    }
}



int main(int argc, char *argv[]){

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);

    SDL_SetRenderDrawColor(renderer, 0,0,0, 255);

    SDL_RenderClear(renderer);


    if (TTF_Init() != 0) {
        std::cerr << "SDL_ttf initialization failed: " << TTF_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    TTF_Font* font = TTF_OpenFont("fonts/AbteciaBasicSansSerifFont-5aev.ttf", 24);

    if (!font) {
        std::cerr << "Font loading failed: " << TTF_GetError() << std::endl;
    }
   
    board currentBoard = board(80, 80, 10);
    UIelements newUI = UIelements(&currentBoard, renderer, font, window, WIDTH, HEIGHT);
    currentBoard.createRandomObstacles();


    newUI.renderAll();

    if (NULL == window){
        cout << "failed" << SDL_GetError()<< endl;
        return 0;
    }

    thread t(inputListener, &newUI);

    SDL_Event windowEvent;

    // Main loop
    while (true){
        Uint32 startTime = SDL_GetTicks();

        // Your rendering code goes here

        
        SDL_RenderClear(renderer);
        if (SDL_PollEvent(&windowEvent)){
            if (SDL_QUIT == windowEvent.type){
                break;
            }
        }


        newUI.renderAll();
        if (currentBoard.getRunAlgo() == true){
            if (currentBoard.getSelectedAlgo() == "bfs"){
                if(bfs(&newUI, currentBoard.getStartNode(), currentBoard.getEndNode())){
                    Traceback(currentBoard.getStartNode(), currentBoard.getEndNode());
                }
            }
            else if (currentBoard.getSelectedAlgo() == "dfs"){
                if(dfs_with_stack(&newUI, currentBoard.getStartNode(), currentBoard.getEndNode())){
                    Traceback(currentBoard.getStartNode(), currentBoard.getEndNode());
                }
            }
            else if (currentBoard.getSelectedAlgo() == "dijkstra"){
                if(dijkstra(&newUI, currentBoard.getStartNode(), currentBoard.getEndNode())){
                    Traceback(currentBoard.getStartNode(), currentBoard.getEndNode());
                }
            }
            else if (currentBoard.getSelectedAlgo() == "A_star"){
                if(a_star(&newUI, currentBoard.getStartNode(), currentBoard.getEndNode())){
                    Traceback(currentBoard.getStartNode(), currentBoard.getEndNode());
                }
            }
            currentBoard.setRunAlgo(false);
        }
        Uint32 endTime = SDL_GetTicks();
        Uint32 frameTime = endTime - startTime;

        float fps = 1000.0f / frameTime;
        // printf("FPS: %.2f\n", fps);

    }

    SDL_DestroyWindow (window);
    SDL_Quit();
    TTF_Quit();

    cout << "success" << endl;


    return EXIT_SUCCESS;
    return 0;
}