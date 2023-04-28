// Codeforces C. Traffic Light - 11/13/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

void solve() {
  int n;
  char color;
  string s;
  cin >> n >> color >> s;
  s += s;
  int ans = INT_MIN, lastGreen = -1;
  vi dists;

  for(int i = 0; i < 2 * n; i++){
    if(s[i] != 'g') continue;
    // otherwise just loop from lastGreen to here and mark as dist
    for(int j = lastGreen + 1; j <= i; j++){
      dists.push_back(i - j);
    }
    lastGreen = i;
  }

  for(int i = 0; i < n; i++){
    if(s[i] != color) continue;
    ans = max(ans, dists[i]);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  cin >> T;
  for (ll i = 0; i < T; i++) solve();


  return 0;
}
