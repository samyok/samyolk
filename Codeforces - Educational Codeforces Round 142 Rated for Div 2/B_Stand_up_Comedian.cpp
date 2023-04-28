// Codeforces B. Stand-up Comedian - 1/24/23

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

void solve() {
  int a1, a2, a3, a4;
  cin >> a1 >> a2 >> a3 >> a4;
  int n = a1;
  if(a1 == 0) {
    cout << min(1, a2 + a3 + a4) << "\n";
    return;
  }
  int y = min(a2, a3);
  n += 2 * y;
  a2 -= y;
  a3 -= y;
  // we should be where we started
  int x = min(a1, a2 + a3 + a4);
  n += x;
  int b = a2, c = a3, d = a4;
  a2 -= min(a2, x);
  a3 -= min(a3, x - b);
  a4 -= min(a4, x - b - c);
  n += min(1, a2 + a3 + a4);
  cout << n << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  cin >> T;
  while (T--) solve();


  return 0;
}
