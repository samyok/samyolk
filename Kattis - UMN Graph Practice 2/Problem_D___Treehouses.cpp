// Kattis Problem D - Treehouses - 11/16/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>


// Prim's algo for minimum spanning tree
// create a pq of edges with key being weight
// can start at any arbitrary node
// add edges to pq for visited nodes
// pop off every node has been visited
void solve() {
  int n, p, e;
  cin >> n >> e >> p;

  priority_queue<pair<double, pl>> edges;
  vector<pl> nodes;
  for (long long i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    nodes.emplace_back(x, y);
  }

  vector<bool> visited(n, false);

  // add edges for the first e
  for (long long i = 0; i < e; i++) {
    pl node = nodes[i];
    visited[i] = true;
    for (long long j = 0; j < n; j++) {
      double dist = pow(pow(node.first - nodes[j].first, 2) + pow(node.second - nodes[j].second, 2), 0.5);
      edges.push({dist, {i, j}});
    }
  }

  // add edges for the F
  for (long long i = 0; i < p; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edges.push({0, {a, b}});
  }

  vector<pl> mst;
  while (mst.size() <= n - 1) {
    auto edge = edges.top();
    edges.pop();
    if(visited[edge.second.second]) continue;
    visited[edge.second.second] = true;
    for (long long i = 0; i < n; i++) {

    }
  }
}

// kruskal's algo for minimum spanning tre


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();

  return 0;
}
