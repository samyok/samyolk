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

  string s;
  cin >> s;
  ll z = 0, o = 0;
  for (long long i = 0; i < s.length(); i++) {
    if(s[i] == '1'){
      z++; o=0;
    } else {
      o++; z=0;
    }
    if(o == 7 || z == 7) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
