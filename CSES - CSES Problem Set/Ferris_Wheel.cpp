// CSES Ferris Wheel - 9/24/22

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

  int n, x, t;
  cin >> n >> x;
  vector<int> c;
  for (long long i = 0; i < n; i++) {
    cin >> t;
    c.push_back(t);
  }

  sort(c.begin(), c.end());

  int lp = 0, ub = n - 1;
  int ans = 0;
  while(lp <= ub){
    if(c[lp] + c[ub] <= x) {
      ans++;
      lp++;
      ub--;
    } else {
      ans++;
      ub--;
    }
  }

  cout << ans;

  return 0;
}

