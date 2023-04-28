// Codeforces D. Fixed Prefix Permutations - 1/24/23

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vi> trie(n * m, vi(11, -1));
  // load into trie:
  int node = 0;

  vector<vi> correct;
  vector<vi> og;
  for (long long i = 0; i < n; i++) {
    vi indexes(m, 0);
    vi x;
    for (int j = 0; j < m; j++) {
      int tmp;
      cin >> tmp;
      indexes[tmp - 1] = j + 1;
      x.push_back(tmp);
    }
    og.push_back(x);

    int prev = 0;
    for(int j = 0; j < m; j++) {
      int tmp = indexes[j];
      if (trie[prev][tmp] == -1) {
        trie[prev][tmp] = node + 1;
        prev = node + 1;
        node++;
      } else {
        prev = trie[prev][tmp];
      }
    }
//    for(auto a: indexes) cout << a << " ";
//    cout << "\n";
    correct.push_back(indexes);
  }
  // print trie:
//  for (long long i = 0; i < node; i++) {
//    for (long long j = 0; j < 10; j++) {
//      cout << trie[i][j] << " ";
//    }
//    cout << "\n";
//  }
//  cout << "\n";

  for(vi a: og) {
    // print prefix of a in trie:
    int prev = 0;
    int cur = 0;
    for(int j = 0; j < m; j++) {
      int tmp = a[j];
      if (trie[prev][tmp] == -1) {
        break;
      } else {
        prev = trie[prev][tmp];
      }
      cur = j + 1;
    }
    cout << cur << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  cin >> T;
  while (T--) solve();


  return 0;
}
