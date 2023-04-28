// Kattis Fiat - 9/26/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

long long MOD = 1e9 + 7;


// modular inverse of a:
// a' congruent to a^{P-2} mod P
// use FME to find a^{P-2} quickly

// fast modular exponentiation
ll fme(ll b, ll e) {
  if (e == 0) return 1;
  if (e % 2 == 0) return fme((b * b) % MOD, e / 2);
  else
    return (fme(b, e - 1) * b) % MOD;
}

//  (2n)!/(n!(n+1)!)
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long n;
  cin >> n;

  long long dn = 1, nf = 1;
  // n + 1
  for (int i = 1; i <= 2 * n; i++) {
    dn *= i;
    if (i <= n) nf *= i;
    dn %= MOD;
    nf %= MOD;
  }


  ll ans = dn * fme(nf, MOD - 2);
  ans %= MOD;
  ans *= fme(nf, MOD - 2);
  ans %= MOD;
  ans *= fme(n + 1, MOD - 2);
  ans %= MOD;

  cout << ans;

  return 0;
}
