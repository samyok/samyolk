// CSES Coin Combinations I - 11/6/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>
ll MOD = 1e9 + 7;


ll powerModP(ll x, ll y, ll p) {
  ll res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}

ll modInverse(ll n, ll p) {
  return powerModP(n, p - 2, p);
}

vl fac = {1};
ll factorial(ll n, ll p) {
  if (fac.size() > n) return fac[n];
  for (ll i = fac.size(); i <= n; i++) fac[i] = (fac[i - 1] * i) % p;

  return fac[n];
}

ll nCrModPFermat(ll n, ll r, ll p) {
  return (factorial(n, p) * modInverse(factorial(r, p), p) % p * modInverse(factorial(n - r, p), p) % p) % p;
}
vector<vl> memo;

ll waysToMake(int x, int c, vector<int> coins, map<int, int> cur) {
  if (x == 0) {
    ll sm = 0;
    ll div = 1;
    for (auto [key, value]: cur) {
//      cout << key << ":" << value << endl;
      sm += value;
      div *= modInverse(factorial(value, MOD), MOD);
    }
//    cout << sm << " " << div << "\n";
    memo[x][c] = (factorial(sm, MOD) * div) % MOD;
    return memo[x][c];
  }
  if (x < 0) return 0;
  if (c == coins.size()) return 0;

  // otherwise, we can keep taking coins
  ll ways = 0;
  for (int i = 0; i <= x / coins[c]; i++) {
//    for(auto a: coins) cout << a << ",";
//    cout << endl;
//    cout << "x: " << x << " coin: " << c << "->" << (coins[c] + 0) << " i: " << i << endl;
    cur[coins[c]] = i;
    ways += waysToMake(x - (i * coins[c]), c + 1, coins, cur);
  }
  memo[x][c] = ways;
  return memo[x][c];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // build up a dp of # of ways to make n.
  int n, x;
  cin >> n >> x;
  vector<int> coins;
  for (ll i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    coins.push_back(tmp);
  }
  map<int, int> cur;
  memo = vector<vl>(x + 1, vl(n + 1, 0));
  cout << waysToMake(x, 0, coins, cur);
  return 0;
}
