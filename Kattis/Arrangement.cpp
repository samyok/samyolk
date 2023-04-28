// Kattis Arrangement - 9/26/22

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

  int n, m; cin >> n >> m;
  int per = m / n;
  int md = m % n;
  string s = "";
  for(int i = 0; i < per; i++) s += "*";

  for (long long i = md; i < n; i++) {
    cout << s << "\n";
  }
  s+= "*";
  for (long long i = 0; i < md; i++) {
    cout << s << "\n";
  }

  return 0;
}
