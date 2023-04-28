// Kattis Problem E - Evading a Monster - 10/29/22

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

  ll n, m;
  cin >> n >> m;

  map<int, vector<int>> adj;

  for (long long i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
  }

  return 0;
}
