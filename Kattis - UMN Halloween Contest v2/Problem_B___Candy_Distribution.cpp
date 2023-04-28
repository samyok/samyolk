// Kattis Problem B - Candy Distribution - 10/29/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>


// Function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll &x, ll &y) {

  // Base Case
  if (a == 0) {
    x = 0, y = 1;
    return b;
  }

  // To store results of recursive call
  ll x1, y1;
  ll gcd = gcdExtended(b % a, a, x1, y1);

  // Update x and y using results of recursive
  // call
  x = y1 - (b / a) * x1;
  y = x1;

  return gcd;
}

// Function to find modulo inverse of a
ll modInverse(ll A, ll M) {
  ll x, y;
  ll g = gcdExtended(A, M, x, y);
  if (g != 1) return -1;
  // m is added to handle negative x
  return (x % M + M) % M;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  for (long long i = 0; i < T; i++) {
    ll a, b;
    cin >> a >> b;
    if(a == 1) {
      if(b == 2) {
        cout << "1\n";
        continue;
      } else {
        cout << "IMPOSSIBLE\n";
        continue;
      }
    }

    if(b > a){
      cout << "IMPOSSIBLE\n";
      continue;
    }
    if(b == 1) {
      if(a >= 1000000000) {
        cout << "IMPOSSIBLE\n";
        continue;
      }
      cout << a << "\n";

      continue;
    }
    ll ans = modInverse(b, a);

    if (ans < 0 || ans > 1e9) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    cout << ans << "\n";
  }

  return 0;
}
