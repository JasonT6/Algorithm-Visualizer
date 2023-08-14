#include <iostream>
#include <vector>
#include "node.hpp"
#include "board.hpp"
#include "algorithms.hpp"
#include "UIclass.hpp"
#include <SDL2/SDL.h>

using namespace std;

const int WIDTH = 1200, HEIGHT = 800;


int main(int argc, char *argv[]){

    SDL_Init(SDL_INIT_EVERYTHING);

    // SDL_Window *window = SDL_CreateWindow("Hello SDL World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);

    SDL_SetRenderDrawColor(renderer, 0,0,0, 255);

    SDL_RenderClear(renderer);

    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // SDL_Rect rect;
    // rect.w = 100;
    // rect.h = 100;
    // rect.y = 0;
    // rect.x = 0;
    // SDL_RenderDrawRect(renderer, &rect);

    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
    // SDL_RenderDrawPoint(renderer, WIDTH/2, HEIGHT/2);

    // SDL_RenderPresent(renderer);
    board currentBoard = board(80, 80, 10);
    UIelements newUI = UIelements(&currentBoard, renderer, window, WIDTH, HEIGHT);
    currentBoard.createRandomObstacles();
    // node * start = currentBoard.getHead();
    // node * current = start;
    // while (current->getEast() != nullptr){
    //     current = current->getEast();
    // }

    // while (current->getSouth() != nullptr){
    //     current = current->getSouth();
    // }
    // node * end = current;

    // currentBoard.setStartNode(start);
    // currentBoard.setEndNode(end);

    // if (bfs(&newUI, start, end)){
    //     Traceback(start, end);
    // }

    newUI.renderAll();

    if (NULL == window){
        cout << "failed" << SDL_GetError()<< endl;
        return 0;
    }

    SDL_Event windowEvent;

    // Main loop
    while (true){
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

    }

    SDL_DestroyWindow (window);
    SDL_Quit();

    cout << "success" << endl;

    


    // TESTCODE
    // node head = node(nullptr, nullptr, nullptr, nullptr, new x_y_position(10, 10));
    // head.setNorth(new node(nullptr, nullptr, nullptr, nullptr, new x_y_position(20, 10)));
    // head.getNorth()->getNodePosition()->getX();
    // cout << head.getNorth()->getNodePosition()->getX() << endl;

    // board currentBoard = board(40, 100, 10);
    // node *current = currentBoard.getHead();
    // node *current = currentBoard.getHead();
    // cout << current->getNodePosition()->getX() << endl;

    // cout << "successfully created board" << endl;

    // currentBoard.printBoard();

    // currentBoard.printBoard();

    // node * start = current;

    // while (current->getEast() != nullptr){
    //     current = current->getEast();
    // }

    // while (current->getSouth() != nullptr){
    //     current = current->getSouth();
    // }

    // node *end = current;

    // cout << "start: " << start << endl;

    // cout << "end: " << end << endl;

    // current = currentBoard.getHead();
    // // for (int i = 0; i < 5; i++){
    // //     current = current->getEast();
    // // }

    // // for (int i = 0; i < 4; i++){
    // //     current->setTraversable(false);
    // //     current = current->getSouth();
    // // }

    // currentBoard.createRandomObstacles();

    // currentBoard.printBoard();

    // // cout << "bfs" << endl;
    // // if (bfs(start, end)){
    // //     Traceback(start, end);
    // // }
    // // else{
    // //     cout << "dfs failed";
    // // }
    
    // currentBoard.printBoard();
     
    // // currentBoard.clearPath();

    

    // cout << "dijkstra" << endl;
    // if (dijkstra(start, end)){
    //     Traceback(start, end);
    // }
    // else{
    //     cout << "dfs failed";
    // }




    // // if (bfs(start, end)){
    // //     Traceback(start, end);
    // // }
    

    // currentBoard.printBoard();

   







    // cout << current << endl;
    // cout << current->getSouth()->getNodePosition()->getY() << endl;
    // cout << current->getSouth()->getSouth()->getNodePosition()->getY() << endl;
    // cout << current->getSouth()->getSouth()->getSouth()->getNodePosition()->getY() << endl;
    // cout << current->getSouth()->getSouth()->getSouth()->getSouth()->getNodePosition()->getY() << endl;

    // cout << current << endl;
    // cout << current->getSouth() << endl;
    // cout << current->getSouth()->getSouth()<< endl;
    // cout << current->getSouth()->getSouth()->getSouth() << endl;
    // cout << current->getSouth()->getSouth()->getSouth()->getSouth()<< endl;

    // current = current->getSouth()->getSouth()->getSouth()->getSouth();
    
    // cout << "swap" << endl;

    // cout << current->getNorth()->getNodePosition()->getY() << endl;
    // cout << current->getNorth()->getNorth()->getNodePosition()->getY() << endl;
    // cout << current->getNorth()->getNorth()->getNorth()->getNodePosition()->getY() << endl;
    // cout << current->getNorth()->getNorth()->getNorth()->getNorth()->getNodePosition()->getY() << endl;

    // cout << current << endl;
    // cout << current->getNorth() << endl;
    // cout << current->getNorth()->getNorth() << endl;
    // cout << current->getNorth()->getNorth()->getNorth() << endl;
    // cout << current->getNorth()->getNorth()->getNorth()->getNorth() << endl;


    // cout << "go east" << endl;

    // cout << current->getNodePosition()->getX() << endl;
    // cout << current->getEast()->getNodePosition()->getX() << endl;
    // cout << current->getEast()->getEast()->getNodePosition()->getX() << endl;
    // // cout << current->getEast()->getEast()->getEast()->getNodePosition()->getX() << endl;

    // current = current->getEast()->getEast();

    // cout << current->getNodePosition()->getX() << endl;
    // cout << current->getWest()->getNodePosition()->getX() << endl;
    // cout << current->getWest()->getWest()->getNodePosition()->getX() << endl;

    // int count = 0;
    // while (current != nullptr){
    //     cout << current << endl;
    //     cout << count << endl;
    //     count++;
    //     current = current->getSouth();
    // }
    // cout << count;

    return EXIT_SUCCESS;
    return 0;
}