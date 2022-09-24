#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int error(int err) {
  cout << "E" << err << "\n";
  return 0;
}

// Returns true if the substring from s[i...i+5] has been parsed successfully into adj.
int parse(string &s, int &index, unordered_map<char, vector<char>> &adj) {
  if (s.size() < index + 5 ||// not a full pair
      s[index] != '(' ||
      s[index + 1] < 'A' || s[index + 1] > 'Z' ||
      s[index + 2] != ',' ||
      s[index + 3] < 'A' || s[index + 3] > 'Z' ||
      s[index + 4] != ')') return 1;

  if (s.size() > index + 5 && s[index + 5] != ' ') return 1;

  for (char child: adj[s[index + 1]])
    if (child == s[index + 3]) return 2;

  adj[s[index + 1]].push_back(s[index + 3]);

  if (adj[s[index + 1]].size() > 2) return 3;

  return 0;
}
// return \0 char if no roots/multiple roots are found.
char findRoot(unordered_map<char, vector<char>> &adj) {
  unordered_map<char, int> roots;
  char root = '\0';

  for (pair<char, vector<char>> node: adj) {
    if (roots[node.first] == 0) roots[node.first] = 1;
    for (char child: node.second) roots[child] = -1;
  }

  for (pair<char, vector<char>> node: adj) {
    if (roots[node.first] == 1) {
      if (root != '\0') return '\0';
      root = node.first;
    }
  }

  return root;
}

// detect cycles through dfs: if we're going to a node that has been visited, we can return false.
bool hasCycles(unordered_map<char, vector<char>> &adj, char root) {
  unordered_map<char, bool> visited;

  stack<char> dfs;
  dfs.push(root);

  while (!dfs.empty()) {
    char top = dfs.top();
    dfs.pop();

    if (visited[top]) return true;
    visited[top] = true;

    for (char child: adj[top]) dfs.push(child);
  }

  return false;
}

string sexp(unordered_map<char, vector<char>> &adj, char letter) {
  string result = {letter};
  if (adj[letter].empty()) return result;

  sort(adj[letter].begin(), adj[letter].end());
  for (char child: adj[letter]) result += "(" + sexp(adj, child) + ")";

  return result;
}

int main() {
  unordered_map<char, vector<char>> adj;

  string line;
  getline(cin, line);

  for (int i = 0; i < line.size(); i += 6) {
    // parse will add it to adj or return an err > 0.
    int err = parse(line, i, adj);
    if (err > 0) return error(err);
  }

  char root = findRoot(adj);
  if (root == '\0') return error(4);

  if (hasCycles(adj, root)) return error(5);

  cout << "(" + sexp(adj, root) + ")";

  return 0;
}