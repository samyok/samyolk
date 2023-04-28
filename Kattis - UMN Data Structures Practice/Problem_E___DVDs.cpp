// Kattis Problem E - DVDs - 10/6/22

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

  ll tests; cin >> tests;
  ll n, tmp, ans, expected;
  for (long long i = 0; i < tests; i++) {
    cin >> n;
    ans = n;
    expected = 1;
    for (long long j = 0; j < n; j++) {
      cin >> tmp;
      if (tmp == expected) {
        expected++;
        ans--;
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
