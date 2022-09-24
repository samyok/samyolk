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

  ll n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    if(s.length() > 10) {
      cout << s[0] << s.length() - 2 << s[s.length() - 1] << "\n";
    } else {
      cout << s << "\n";
    }
  }

  return 0;
}
