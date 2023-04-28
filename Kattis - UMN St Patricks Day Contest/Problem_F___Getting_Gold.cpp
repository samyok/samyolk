// Kattis Problem F - Getting Gold - 3/18/23

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

void print_map(vector<vector<char>> &map) {
  for (auto &row: map) {
    for (auto &col: row) {
      cout << col;
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int rows, cols;
  cin >> cols >> rows;

  // load map
  vector<vector<char>> map(rows, vector<char>(cols));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> map[i][j];
    }
  }

  // find start
  int startRow, startCol;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (map[i][j] == 'P') {
        startRow = i;
        startCol = j;
      }
    }
  }

  int gold = 0;

  // bfs from start and see how many gold we can hit, if we are adjacent to a trap we have to end the path there
  queue<pair<int, int>> q;
  q.emplace(startRow, startCol);

  const vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  set<pair<int, int>> visited;

  while (!q.empty()) {
    auto [row, col] = q.front();
    q.pop();
    visited.insert({row, col});

    if (map[row][col] == 'G') {
      gold++;
      map[row][col] = 'X';
    }

    // check around for traps
    bool trap = false;
    for (auto [dr, dc]: dirs) {
      int r = row + dr, c = col + dc;
      if (r < 0 || r >= rows || c < 0 || c >= cols || visited.count({r, c})) {
        continue;
      }

      if (map[r][c] == 'T') {
        trap = true;
      }
    }
    if (trap) {
      continue;
    }

    for (auto [dr, dc]: dirs) {
      int r = row + dr, c = col + dc;
      if (r < 0 || r >= rows || c < 0 || c >= cols) {
        continue;
      }
      if (visited.count({r, c}) || map[r][c] == '#') {
        continue;
      }
      q.emplace(r, c);
    }

//    print_map(map);
  }

  cout << gold << endl;

  return 0;
}
