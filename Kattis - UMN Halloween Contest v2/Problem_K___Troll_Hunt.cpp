// Kattis Problem K - Troll Hunt - 10/29/22

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

  int b, k, g = 0;
  cin >> b >> k >> g;
  b--;
  int n = k/g;
  double d = b/n;
  if (b % n > 0) d++;
  int ans = ceil(d);
  cout << ans << endl;
  return 0;
}
