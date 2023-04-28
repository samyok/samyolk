// Kattis Problem C - Robots on a Grid - 10/10/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

ll MOD = pow(2, 31) - 1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  vector<vl> mp;

  mp.push_back(vl(n, 0));
  mp[0][0] = 1;

  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    vl row;

    row.push_back(s[0] == '.' ? mp.back()[0] : 0);
    for (long long j = 1; j < n; j++) {
      row.push_back(s[j] == '.' ? (row.back() + mp.back()[j]) % MOD : 0);
    }
    mp.push_back(row);
  }
  ll ans = mp.back().back();
  if(ans == 0) cout << "THE GAME IS A LIE";
  else cout << ans;

  return 0;
}
