#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <algorithm>

using namespace std;

const int rows = 15;
const int cols = 15;

enum CellType {
    WALL,
    PATH,
    ENTRY,
    EXIT,
    SOLUTION
};

struct Cell {
    int row;
    int col;
    CellType type;
};

void printMaze(const vector<vector<Cell>>& maze) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            switch (maze[i][j].type) {
                case WALL:
                    cout << '#';
                    break;
                case PATH:
                    cout << '.';
                    break;
                case ENTRY:
                    cout << 'E';
                    break;
                case EXIT:
                    cout << 'X';
                    break;
                case SOLUTION:
                    cout << '+';
                    break;
            }
        }
        cout << endl;
    }
}

bool isValid(int row, int col) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

vector<vector<Cell>> generateMaze() {
    vector<vector<Cell>> maze(rows, vector<Cell>(cols, {0, 0, WALL}));

    // Initialize random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Set entry and exit
    maze[0][1].type = ENTRY;
    maze[rows - 1][cols - 2].type = EXIT;

    // Generate a simple connected path from entry to exit
    for (int i = 1; i < rows - 1; i += 2) {
        for (int j = 1; j < cols - 1; j += 2) {
            maze[i][j].type = PATH;

            if (i < rows - 2 && rand() % 2 == 0) {
                maze[i + 1][j].type = PATH;
            }

            if (j < cols - 2 && rand() % 2 == 0) {
                maze[i][j + 1].type = PATH;
            }
        }
    }

    // Ensure there are no dead ends
    for (int i = 1; i < rows - 1; i += 2) {
        for (int j = 1; j < cols - 1; j += 2) {
            int count = 0;
            if (maze[i - 1][j].type == PATH) count++;
            if (maze[i + 1][j].type == PATH) count++;
            if (maze[i][j - 1].type == PATH) count++;
            if (maze[i][j + 1].type == PATH) count++;

            // If there's only one path, mark it as a wall
            if (count == 1) {
                maze[i][j].type = WALL;
            }
        }
    }

    return maze;
}

bool solveMaze(vector<vector<Cell>>& maze, int row, int col) {
    if (!isValid(row, col) || maze[row][col].type != PATH) {
        return false;
    }

    // Check if we reached the exit
    if (maze[row][col].type == EXIT) {
        return true;
    }

    // Mark the current cell as part of the solution path
    maze[row][col].type = SOLUTION;

    // Explore in all directions
    if (solveMaze(maze, row - 1, col) ||  // Up
        solveMaze(maze, row + 1, col) ||  // Down
        solveMaze(maze, row, col - 1) ||  // Left
        solveMaze(maze, row, col + 1))    // Right
    {
        return true;
    }

    // If none of the directions lead to the exit, backtrack
    maze[row][col].type = PATH;
    return false;
}


int main() {
    vector<vector<Cell>> maze = generateMaze();

    cout << "Generated Maze:" << endl;
    printMaze(maze);

    // Find and display the solution path
    solveMaze(maze, 0, 1);  // Start solving from the entry point
    cout << "\nMaze with Solution Path:" << endl;
    printMaze(maze);

    return 0;
}
