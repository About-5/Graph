#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include "Maze.h"

using namespace std;

int main()
{
    int** maze = createMaze(WIDTH, HEIGHT);

    printMaze(maze);

    return 0;
}