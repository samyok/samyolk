// Kattis Problem C - Candy Division - 10/29/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>
// a set of all the factors of n
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
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n;
  cin >> n;

  set<ll> x = getDivisors(n);
  for (ll a: x) cout << a-1 << " ";
  cout << endl;

  return 0;
}
