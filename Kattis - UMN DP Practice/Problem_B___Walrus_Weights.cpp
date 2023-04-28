// Kattis Problem B - Walrus Weights - 10/10/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  unordered_set<int> weights;
  weights.insert(0);

  int more = INT_MAX, less = 0;

  for (long long i = 0; i < n; i++) {
    int nw; cin >> nw;

    unordered_set<int> nws(weights.begin(), weights.end());
    for(int w: nws) {
      int nt = nw + w;
      if(nt >= 1000) more = min(nt, more);
      else less = max(nt, less);

      if(nt <= more) weights.insert(nt);
    }
  }

  if(abs(more - 1000) <= abs(less - 1000)) cout << more;
  else cout << less;

  return 0;
}
