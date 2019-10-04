#include <stdlib.h>
#include <iostream>
#include <unistd.h>

#define WIDTH 25
#define HEIGHT 25

using namespace std;

class Maze {
    public:
    Maze(int width, int height);
    int getCell(int x, int y);
    void generatePath(int** maze, int row, int col);
    int* randomizeDirections();
    void printMaze();
    
    private:
    int** grid;
};

