// CSES Collecting Numbers - 9/24/22

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

  ll n, tmp;
  cin >> n;

  set<ll> s;
  s.insert(0);

  ll ans = 1;
  for (long long i = 0; i < n; i++) {
    cin >> tmp;
    if(s.count(tmp - 1) == 0) ans++;
    s.insert(tmp);
  }

  cout << ans;
  return 0;
}
