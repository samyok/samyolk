// Kattis Problem D - ICPC Team Selection - 1/18/23

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>


void solve() {

  int n; cin >> n;
  vi team;
  int tmp;
  for (long long i = 0; i < 3 * n; i++) {
    cin >> tmp;
    team.push_back(tmp);
  }
  sort(team.begin(), team.end());
  int sum = 0;
  for (long long i = 0; i < n; i++) {
    team.pop_back();
    sum += team.back();
    team.pop_back();
  }
  cout << sum << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  cin >> T;
  while (T--) solve();


  return 0;
}