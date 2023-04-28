// Kattis Problem D - I Hate The Number Nine - 10/8/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

const long long MOD = 1000000007;

// fast modular exponentiation
ll fme(ll b, ll e) {
  if (e == 0) return 1;
  if (e % 2 == 0) return fme((b * b) % MOD, e / 2);
  else
    return (fme(b, e - 1) * b) % MOD;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (long long i = 0; i < n; i++) {
    long long tmp; cin >> tmp;
    long long ans = 1;
    ans *= fme(9, tmp - 1);
    ans *= 8;
    ans %= MOD;
    cout << ans << "\n";
  }
  return 0;
}
