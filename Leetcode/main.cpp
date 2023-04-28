// Kattis Hello World! - 9/24/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>


int ans = 0;
vector<int> v;
bool visited[(int)3e4 + 2];

unordered_map<int, vector<int>> adj;

void dfs(int &i) {
  // go downstream for every val, until
  queue<int> d;
  d.push(i);
  int start = v[i];
  memset(visited, 0, sizeof(visited));

  while (!d.empty()) {
    int top = d.front();

    d.pop();
    if (visited[top]) continue;
    visited[top] = true;

    if (v[top] == start && top != i) ans++;

    for (auto a: adj[top]) {
      if (v[a] <= start && !visited[a]) d.push(a);
    }
  }
}

int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges) {
  // can we just dfs downstream from every point, and then if we hit anything bigger we just stop

  for (auto edge: edges) {
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
  }
  v = vals;

  for (int i = 0; i < vals.size(); i++) {
    dfs(i);
  }
  return ans / 2 + vals.size();
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);


//  vector<int> vals = {1, 3, 2, 1, 3};
//  vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}};

  vector<int> vals = {2,5,5,1,5,2,3,5,1,5};
  vector<vector<int>> edges = {{0,1},{2,1},{3,2},{3,4},{3,5},{5,6},{1,7},{8,4},{9,7}};
  cout << numberOfGoodPaths(vals, edges) << endl;


  return 0;
}