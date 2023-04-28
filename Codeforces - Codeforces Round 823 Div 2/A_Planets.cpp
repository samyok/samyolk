// Codeforces A. Planets - 9/25/22

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

  int tests; cin >> tests;

  for (long long i = 0; i < tests; i++) {
    int n, c, tmp;
    cin >> n >> c;
    unordered_map<int, int> m;
    for (long long j = 0; j < n; j++) {

      cin >> tmp;
      m[tmp]++;
    }
    ll ans = 0;
    for(auto [key, value]: m) {
      ans += min(value, c);
    }
    cout << ans << "\n";
  }


  return 0;
}
