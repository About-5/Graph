#include <stdlib.h>
#include <iostream>
#include <unistd.h>

#define WIDTH 25
#define HEIGHT 25

using namespace std;

class Maze {
    public:
    Maze::Maze(int width, int height);
    private:
    int** grid;
};

int** createMaze(int width, int height);
void generatePath(int** maze, int row, int col);
int* randomizeDirections();
void printMaze(int** maze);