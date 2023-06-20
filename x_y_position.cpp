#include "x_y_position.hpp"

x_y_position::x_y_position(int new_x, int new_y){
    x = new_x;
    y = new_y;
    return;
}

int x_y_position::getX(){
    return x;
}

int x_y_position::getY(){
    return y;
}

void x_y_position::setX(int new_x){
    x = new_x;
    return;
}

void x_y_position::setY(int new_y){
    y = new_y;
    return;
}

map <char, int> x_y_position::getPosition(){
    map <char, int> position;
    position['x'] = x;
    position['y'] = y;
    return position;
}