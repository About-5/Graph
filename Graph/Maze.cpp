#include "Maze.h"

void printMaze(int** maze)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int** createMaze(int width, int height)
{
    // cout << "maze" << endl;
    srand(time(0));
    int** maze = new int*[height];

    for (int i = 0; i < height; i++)
    {
        maze[i] = new int[width];
        for (int j = 0; j < width; j++)
        {
            maze[i][j] = 0;
        }
    }

    int row = rand() % (height - 2) + 1;
    int col = rand() % (width - 2) + 1;

    cout << row << " " << col << endl;

    if (row % 2 != 1)
    {
        row *= 2;
        row /= 2;
        row--;
    }
    if (col % 2 != 1)
    {
        col *= 2;
        col /= 2;
        col--;
    }

    cout << row << " " << col << endl;

    maze[row][col] = 1;

    generatePath(maze, row, col);

    return maze;
}

void generatePath(int** maze, int row, int col)
{
    int* directions = randomizeDirections();
    
    for (int i = 0; i < 4; i++)
    {
        switch (directions[i])
        {
            case 0: // North
            if (row - 2 < 0) continue;
            if (maze[row - 2][col] != 1)
            {
                maze[row - 1][col] = 1;
                maze[row - 2][col] = 1;
                generatePath(maze, row - 2, col);
            }
            break;
            case 1: // East
            if (col + 2 > WIDTH - 1) continue;
            if (maze[row][col + 2] != 1)
            {
                maze[row][col + 1] = 1;
                maze[row][col + 2] = 1;
                generatePath(maze, row, col + 2);
            }
            break;
            case 2: // South
            if (row + 2 > HEIGHT - 1) continue;
            if (maze[row + 2][col] != 1)
            {
                maze[row + 1][col] = 1;
                maze[row + 2][col] = 1;
                generatePath(maze, row + 2, col);
            }
            break;
            case 3: // West
            if (col - 2 < 0) continue;
            if (maze[row][col - 2] != 1)
            {
                maze[row][col - 1] = 1;
                maze[row][col - 2] = 1;
                generatePath(maze, row, col - 2);
            }
            break;
            default:
            cout << "Something went wrong" << endl;
            break;
        }
    }
}

int* randomizeDirections()
{
    int choice = rand() % 24;
    int* directions;

    switch (choice)
    {
        case 0:
        directions = new int[4] {0, 1, 2, 3};
        break;
        case 1:
        directions = new int[4] {0, 1, 3, 2};
        break;
        case 2:
        directions = new int[4] {0, 2, 1, 3};
        break;
        case 3:
        directions = new int[4] {0, 2, 3, 1};
        break;
        case 4:
        directions = new int[4] {0, 3, 1, 2};
        break;
        case 5:
        directions = new int[4] {0, 3, 2, 1};
        break;
        case 6:
        directions = new int[4] {1, 0, 2, 3};
        break;
        case 7:
        directions = new int[4] {1, 0, 3, 2};
        break;
        case 8:
        directions = new int[4] {1, 2, 0, 3};
        break;
        case 9:
        directions = new int[4] {1, 2, 3, 0};
        break;
        case 10:
        directions = new int[4] {1, 3, 0, 2};
        break;
        case 11:
        directions = new int[4] {1, 3, 2, 0};
        break;
        case 12:
        directions = new int[4] {2, 0, 1, 3};
        break;
        case 13:
        directions = new int[4] {2, 0, 3, 1};
        break;
        case 14:
        directions = new int[4] {2, 1, 0, 3};
        break;
        case 15:
        directions = new int[4] {2, 1, 3, 0};
        break;
        case 16:
        directions = new int[4] {2, 3, 0, 1};
        break;
        case 17:
        directions = new int[4] {2, 3, 1, 0};
        break;
        case 18:
        directions = new int[4] {3, 0, 1, 2};
        break;
        case 19:
        directions = new int[4] {3, 0, 2, 1};
        break;
        case 20:
        directions = new int[4] {3, 1, 0, 2};
        break;
        case 21:
        directions = new int[4] {3, 1, 2, 0};
        break;
        case 22:
        directions = new int[4] {3, 2, 0, 1};
        break;
        case 23:
        directions = new int[4] {3, 2, 1, 0};
        break;
    }
    return directions;
}