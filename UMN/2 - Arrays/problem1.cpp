/*
ID: samyok1
TASK: main
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

typedef vector<int> vi;
typedef vector<ll> vl;

const ll INF = 1e18;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // code here
  int n, k; cin >> n >> k;

  map<int, int> frq;

  for (long long i = 0; i < n; i++) {
    int tmp; cin >> tmp;
    frq[tmp]++;
    frq[tmp + 1000]--;
  }
  int mx = 0, cur = 0;
  for(auto [key, val]: frq) {
    cur += val;
    mx = max(mx, cur);
  }

  cout << ((mx - 1) / k) + 1;
  return 0;
}
