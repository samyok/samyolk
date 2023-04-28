// Kattis Problem F - Ghostbusters - 10/29/22

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

  int n, m;
  cin >> n >> m;
  vector<vector<double>> mp;
  for (long long i = 0; i < n; i++) {
    vector<double> tmp; double t;
    for (long long j = 0; j < m; j++) {
      cin >> t;
      tmp.push_back(t);
    }
    mp.push_back(tmp);
  }

  map<int,set<int>> press;

  for (long long i = 0; i < m; i++) {
    int k; cin >> k;
    int mx = 0;

    int c;
    for (long long j = 0; j < k; j++) {
      cin >> c;
      if(mp[i][c] > mp[i][mx]) {
        curMax = mp[i][mx];
      }
      if(curMax == mp[i][c]) mx.push_back(c);
    }

    for(double a: mx) cout << i << " " << a << "\n";
  }


  return 0;
}
