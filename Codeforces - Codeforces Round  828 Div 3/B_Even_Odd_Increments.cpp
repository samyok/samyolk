// Codeforces B. Even-Odd Increments - 11/13/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

void solve() {
  int n, q; cin >> n >> q;
  ll odds = 0, evens = 0, sum = 0;
  for (long long i = 0; i < n; i++) {
    int e; cin >> e;
    sum += e;
    odds += (e %2 == 1);
    evens += (e % 2 == 0);
  }

  for (long long i = 0; i < q; i++) {
    int type, x;
    cin >> type >> x;
    if(type == 1){
      sum += x * odds;
      if(x % 2 == 1){
        evens += odds;
        odds = 0;
      }
    } else {
      sum +=  x * evens;
      if(x % 2 == 1) {
        odds += evens;
        evens = 0;
      }
    }
    cout << sum << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T; cin >> T;
  for(ll i = 0; i < T; i++) solve();

  return 0;
}
