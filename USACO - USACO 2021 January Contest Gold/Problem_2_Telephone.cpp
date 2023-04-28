// USACO Problem 2. Telephone - 4/26/23

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vi>

const int MAXN = 5e4;
int N, K, breed[MAXN];
bool visited[MAXN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  vvi talk(K + 1, vi()), locs(K + 1, vi());

  for (int i = 0; i < N; i++) cin >> breed[i];

  int goal = breed[N - 1];
  for (int r = 1; r <= K; r++) {
    string row;
    cin >> row;
    for (int c = 1; c <= K; c++) {
      if (row[c - 1] == '1') {
        talk[r].push_back(c);
        if (c == goal) talk[r].push_back(0);
      }
    }
  }

  breed[N - 1] = 0;

  vvi fwd(N, vi(K + 1, -1)), bkd(N, vi(K + 1, -1));
  fwd[0][breed[0]] = 0;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= K; j++) {
      if (j == breed[i]) fwd[i][j] = 0;
      else if (fwd[i - 1][j] > -1)
        fwd[i][j] = fwd[i - 1][j] + 1;
    }
  }

  bkd[N - 1][breed[N - 1]] = 0;
  for (int i = N - 2; i >= 0; i--) {
    for (int j = 0; j <= K; j++) {
      if (j == breed[i]) bkd[i][j] = 0;
      else if (bkd[i + 1][j] > -1)
        bkd[i][j] = bkd[i + 1][j] + 1;
    }
  }

  priority_queue<pi> pq;// cost, index
  pq.emplace(0, 0);
  while (!pq.empty()) {
    auto [cost, loc] = pq.top();
    int br = breed[loc];
    pq.pop();

    if (loc == N - 1) {
      cout << -cost;
      return 0;
    }

    if (visited[loc]) continue;
    visited[loc] = true;

    for (auto nextBreed: talk[br]) {
      // see if we can go forwards or backwards
      if (nextBreed == br) continue;
      int f = fwd[loc][nextBreed], b = bkd[loc][nextBreed];
      if (f > 0) pq.emplace(cost - f, loc - f);
      if (b > 0) pq.emplace(cost - b, loc + b);
    }
  }

  cout << -1;

  return 0;
}
