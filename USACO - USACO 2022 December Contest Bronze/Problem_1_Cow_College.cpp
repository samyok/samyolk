// USACO Problem 1. Cow College - 4/28/23

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

void solve() {
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n; cin >> n;

  vector<int> cows(n, 0);
  for (long long i = 0; i < n; i++) {
    cin >> cows[i];
  }

  sort(cows.begin(), cows.end());

  ll mx = 0, mxn = 0;
  for (long long i = 0; i < n; i++) {
    ll c = cows[i] * (n - i);
    if (c > mx) {
      mxn = cows[i];
      mx = c;
    }
  }

  cout << mx << " " << mxn << " ";

  return 0;
}
