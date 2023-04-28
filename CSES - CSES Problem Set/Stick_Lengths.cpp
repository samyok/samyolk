// CSES Stick Lengths - 9/24/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

vl logs;
ll delta(ll x) {
  ll sm = 0;
  for (ll log: logs) sm += abs(log - x);
  return sm;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // we can tell if we're above or below the optimal sol based on if doing diff(n + 1) is more or less.
  ll n, t;
  cin >> n;

  ll low = 1e9 + 1, high = 0;

  for (long long i = 0; i < n; i++) {
    cin >> t;
    logs.push_back(t);
    high = max(high, t);
    low = min(low, t);
  }

  while (high - low > 1) {
    ll mid = (low + high) / 2;
    if (delta(mid) > delta(mid + 1)) low = mid;
    else high = mid;
  }

  cout << delta(high);


  return 0;
}
