// Codeforces B. Meeting on the Line - 9/25/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>
int n;
vector<double> positions;
vector<double> times;


void solve() {
  ll n;
  cin >> n;
  vector<double> p(n), t(n);

  for (int i = 0; i < n; ++i) cin >> p[i];
  for (int i = 0; i < n; ++i) cin >> t[i];

  double mn = 1e9, mx = -1e9;

  for (int i = 0; i < n; ++i) {
    mn = min(mn, p[i] - t[i]);
    mx = max(mx, p[i] + t[i]);
  }

  cout << setprecision(16) <<(mn + mx) / 2.0 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) solve();

  return 0;
}
