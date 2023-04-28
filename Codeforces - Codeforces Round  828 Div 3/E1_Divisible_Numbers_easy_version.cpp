// Codeforces E1. Divisible Numbers (easy version) - 11/13/22

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

void solve() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << a << "-" << c << "\n";
  ll lcm = a * b / gcd(a, b);
  set<ll> factors = getDivisors(lcm);
  // we loop through factors and see if we can find any factors f such that a < f <= b
  for(ll f: factors){
    ll y = lcm/f;
    cout << f << ":" << y << " ";
    if(f > a && f<=c && y > b && y <= d) {
      cout << f << " " << y << "\n";
      return;
    }
  }
  cout << "-1 -1\n";
  cout << "----" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  cin >> T;
  for (ll i = 0; i < T; i++) solve();


  return 0;
}
