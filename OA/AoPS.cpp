// AoPS Application Problem for Samyok Nepal
// uses cin and cout -- enter one blank line after all inputs are done!
#include <bits/stdc++.h>
using namespace std;

int target;
vector<vector<int>> pyramid;
string path = "";

bool dfs(int r, int c) {
  // go until we hit the bottom of the pyramid
  if (r == pyramid.size() - 1)
    return target == 1;

  // at each position, we can either go left (row + 1, col) or right (row + 1,
  // col + 1)
  int left = pyramid[r + 1][c], right = pyramid[r + 1][c + 1];

  if (target % left == 0) {
    target /= left;
    if (dfs(r + 1, c)) {
      path = "L" + path;
      return true;
    }
    target *= left;
  }

  if (target % right == 0) {
    target /= right;
    if (dfs(r + 1, c + 1)) {
      path = "R" + path;
      return true;
    }
    target *= right;
  }

  return false;
}

int main() {

  // the string "Target: "
  string dummy;
  cin >> dummy;

  // the actual target
  cin >> target;
  cin.ignore();

  // load pyramid from standard in to 2d vector line by line, until there is a
  // blank line
  string line;
  while (getline(cin, line) && line != "") {
    vector<int> row;
    int current = 0;
    for (char c : line) {
      if (c == ',') {
        row.push_back(current);
        current = 0;
      } else {
        current = current * 10 + (c - '0');
      }
    }

    // add the last number + add row to pyramid
    row.push_back(current);
    pyramid.push_back(row);
  }

  target /= pyramid[0][0];
  if (dfs(0, 0))
    cout << path << endl;
  else
    cout << "Impossible" << endl;

  return 0;
}
