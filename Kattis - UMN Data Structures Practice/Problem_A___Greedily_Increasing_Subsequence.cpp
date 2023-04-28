// Kattis Problem A - Greedily Increasing Subsequence - 10/3/22

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


  ll n;
  cin >> n;
  ll tmp;
  vl ans;
  cin >> tmp;
  ans.push_back(tmp);
  while (cin >> tmp) {
    if (tmp > ans.back()) ans.push_back(tmp);
  }
  cout << ans.size() << "\n";
  for (ll a: ans) cout << a << " ";

  return 0;
}
