#pragma once
#include <vector>
#include <map>

using namespace std;

class x_y_position{
    private:
        int x;
        int y;

    public:

        x_y_position(int new_x, int new_y);

        int getX();
        int getY();

        void setX(int new_x);
        void setY(int new_y);

        map <char, int> getPosition();
};