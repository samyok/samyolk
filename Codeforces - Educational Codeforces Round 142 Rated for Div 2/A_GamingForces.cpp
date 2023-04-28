// Codeforces A. GamingForces - 1/24/23

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

void solve() {
  int n; cin >> n;
  int ones = 0, nonOnes = 0;
  for (long long i = 0; i < n; i++) {
    int tmp; cin >> tmp;
    if(tmp == 1) ones++;
    else nonOnes++;
  }
  int x = ones/2;
  cout << (n - x) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  cin >> T;
  while (T--) solve();


  return 0;
}
