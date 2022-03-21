#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
using namespace std;

constexpr int MIN = 1;
constexpr int MAX = 100;

constexpr int HEIGHT = 4;
constexpr int WIDTH = 4;
vector<vector<int>> maze(WIDTH, vector<int>(HEIGHT));

// http://www.migapro.com/depth-first-search/
vector<int> generateRandomDirections();

void recursion(int r, int c) {
  // 4 random directions
  vector<int> randDirs = generateRandomDirections();
  // Examine each direction
  for (int i = 0; i < randDirs.size(); i++) {


    switch(randDirs[i]){
      case 1: // Up
        //　Whether 2 cells up is out or not
        if (r - 2 <= 0)
          continue;
        if (maze[r - 2][c] != 1) {
          maze[r-2][c] = 1;
          maze[r-1][c] = 1;
          //cout << "(UP"<<(r-2) <<", " << c << ")";
          //cout <<"(UP"<< (r-1) << ", " << c << ")";
          recursion(r - 2, c);
        }
        break;
      case 2: // Right
        // Whether 2 cells to the right is out or not
        if (c + 2 >= WIDTH - 1)
          continue;
        if (maze[r][c + 2] != 1) {
          maze[r][c + 2] = 1;
          maze[r][c + 1] = 1;
          //cout << "(R"<<(r-2) <<", " << c << ")";
         // cout <<"(R"<< (r-1) << ", " << c << ")";
          recursion(r, c + 2);
        }
        break;
      case 3: // Down
        // Whether 2 cells down is out or not
        if (r + 2 >= HEIGHT - 1)
          continue;
        if (maze[r + 2][c] != 1) {
          maze[r+2][c] = 1;
          maze[r+1][c] = 1;
         // cout << "(D"<<(r-2) <<", " << c << ")";
         // cout <<"(D"<< (r-1) << ", " << c << ")";
          recursion(r + 2, c);
        }
        break;
      case 4: // Left
        // Whether 2 cells to the left is out or not
        if (c - 2 <= 0)
          continue;
        if (maze[r][c - 2] != 1) {
          maze[r][c - 2] = 1;
          maze[r][c - 1] = 1;
         // cout << "(L"<<(r-2) <<", " << c << ")";
         // cout <<"(L"<< (r-1) << ", " << c << ")";
          recursion(r, c - 2);
        }
        break;
    }
  }

}

vector<vector<int>> generateMaze() {

  std::random_device rd;
  std::default_random_engine eng(rd());
  std::uniform_int_distribution<int> distr(MIN, HEIGHT);

  // Initialize
  for (int i = 0; i < HEIGHT; i++)
    for (int j = 0; j < WIDTH; j++)
      maze[i][j] = 0;

 // Random rand = new Random();
  // r for row、c for column
  // Generate random r
  int r = distr(eng); //rand.nextInt(HEIGHT);
  while (r % 2 == 0) {
    r = distr(eng);
  }
  // Generate random c
  int c = distr(eng); //rand.nextInt(WIDTH);
  while (c % 2 == 0) {
    c = distr(eng);//rand.nextInt(WIDTH);
  }
  // Starting cell
  maze[r][c] = 1;

  //　Allocate the maze with recursive method
  recursion(r, c);

  return maze;
}

int main() {

  cout << endl;
  vector<vector<int>> result = generateMaze();
  for (int i = 0; i < HEIGHT; i++) {
    cout << "{";
    for (int j = 0; j < WIDTH; j++) {
      cout << result[i][j] << ",";
    }
    cout << "},"<<endl;
  }


  return 0;
}
/**
* Generate an array with random directions 1-4
* @return Array containing 4 directions in random order
*/
vector<int> generateRandomDirections() {

  std::random_device rd;
  vector<int> randomDirection;
  randomDirection.reserve(4);
  for (int i = 0; i < 4; i++) {
    randomDirection.emplace_back(i+1);
  }
  std::shuffle(randomDirection.begin(), randomDirection.end(), rd);
  return randomDirection;
}

// https://www.softwaretestinghelp.com/cpp-dfs-program-to-traverse-graph/


// https://www.techiedelight.com/find-total-number-unique-paths-maze-source-destination/
