// Codeforces D. Divisibility by 2^n - 11/13/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

int howManyZerosAtTheEndOfANumber(ll n) {
  int ct = 0;
  while (n > 0 && (n & 1) == 0) {
    ct++;
    n >>= 1;
  }
  return ct;
}

void solve() {
  ll n;
  cin >> n;
  int a = 0;
  priority_queue<int> pq;
  for (long long i = 0; i < n; i++) {
    ll tmp;
    cin >> tmp;
    a += howManyZerosAtTheEndOfANumber(tmp);
    pq.push(howManyZerosAtTheEndOfANumber(i+1));
  }
  int ans = 0;
  while(a < n && !pq.empty()) {
    ans ++;
    a += pq.top();
    pq.pop();
  }
  if(a < n) cout << "-1\n";
  else cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  cin >> T;
  for (ll i = 0; i < T; i++) solve();


  return 0;
}
