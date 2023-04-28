// Codeforces E. Divisors and Table - 1/24/23

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

set<ll> getDivisors(ll n) {
  set<ll> ans;
  // Note that this loop runs till square root
  for (ll i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      // If divisors are equal, print only one
      if (n / i == i)
        ans.insert(i);

      else {
        ans.insert(i);
        ans.insert(n / i);
      }
    }
  }
  return ans;
}

ll anypair(ll a, ll n){
  set<ll> x = getDivisors(a);
  for(ll b: x){
//    cout << b << ",";
    if(a / b <= n && b <= n) return min(a / b, b);
  }
  return 0;

}
void solve() {
  ll n, m1, m2;
  cin >> n >> m1 >> m2;
  set<ll> x = getDivisors(m1 * m2);
  ll ans = 0, ct = 0;
  for(ll a: x) {
    ll row = anypair(a, n);
    if(row > 0) ct++;
    ans ^= row;
  }
  cout << ct << " " << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  cin >> T;
  while (T--) solve();


  return 0;
}
