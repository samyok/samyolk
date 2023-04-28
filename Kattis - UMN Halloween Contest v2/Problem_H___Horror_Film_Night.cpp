// Kattis Problem H - Horror Film Night - 10/29/22

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

  vector<ll> lk(10000000, 0);
  deque<ll> a, b;

  ll tmp, k; cin >> k;
  for (long long i = 0; i < k; i++) {
    cin >> tmp;
    a.push_back(tmp);
  }
  sort(a.begin(), a.end());

  cin >> k;
  for (long long i = 0; i < k; i++) {
    cin >> tmp;
    b.push_back(tmp);
  }
  sort(b.begin(), b.end());

  while

  ll ans = 0;
  cout << ans;

  return 0;
}
