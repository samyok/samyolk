/*
ID: samyok1
TASK: main
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

typedef vector<int> vi;
typedef vector<ll> vl;

const ll INF = 1e18;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // code here

  int m, n;
  cin >> m >> n;
  if (m % 2 == 0 || n % 2 == 0) cout << (m * n / 2);
  else cout << (m * n - 1) / 2;
  return 0;
}
