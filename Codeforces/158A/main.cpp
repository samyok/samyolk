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

  int n, k;
  cin >> n >> k;
  int bar;

  // move to bar
  for (long long i = 0; i < k; i++) {
    cin >> bar;
    if(bar == 0) {
      cout << i;
      return 0;
    }
  }

  int a;
  for (long long i = k; i < n; i++) {
    cin >> a;
    if(a != bar){
      cout << i;
      return 0;
    }
  }

  cout << n;
  return 0;
}
