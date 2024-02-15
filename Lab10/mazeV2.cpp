#include <iostream>
#include <random>

using namespace std;

const int width = 15;
const int height = 15;

bool isSafe(int y, int x, vector<vector<bool>>& maze) {
  return (y >= 0 && y < height) && (x >= 0 && x < width) && !maze[y][x];
}

void createMaze(vector<vector<bool>>& maze) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(0, 1);

  // Mark all cells as walls
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      maze[i][j] = true;
    }
  }

  // Create random passages
  for (int i = 0; i < width * height / 2; i++) {
    int x = dis(gen);
    int y = dis(gen);
    if (maze[y][x]) {
      maze[y][x] = false;
      // Ensure passages are connected horizontally or vertically
      if (dis(gen)) {
        if (x > 0 && maze[y][x - 1]) {
          maze[y][x - 1] = false;
        } else if (x < width - 1 && maze[y][x + 1]) {
          maze[y][x + 1] = false;
        }
      } else {
        if (y > 0 && maze[y - 1][x]) {
          maze[y - 1][x] = false;
        } else if (y < height - 1 && maze[y + 1][x]) {
          maze[y + 1][x] = false;
        }
      }
    }
  }

  // Create entry and exit
  maze[0][0] = false;
  maze[width - 1][height - 1] = false;
}

void printMaze(const vector<vector<bool>>& maze) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << (maze[i][j] ? '#' : ' ');
    }
    cout << endl;
  }
}

int main() {
  vector<vector<bool>> maze(height, vector<bool>(width));
  createMaze(maze);
  printMaze(maze);
  return 0;
}
