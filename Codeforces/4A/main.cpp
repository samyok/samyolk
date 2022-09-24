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

  ll w;
  cin >> w;
  if (w % 2 == 0 && w > 2) cout << "YES";
  else
    cout << "NO";
  return 0;
}
