#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include "Maze.h"

using namespace std;

int main()
{
    Maze maze(WIDTH, HEIGHT);

    maze.printMaze();

    return 0;
}