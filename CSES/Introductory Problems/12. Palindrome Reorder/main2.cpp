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

  map<char, int> m;

  for (char c: s) {
    if (m.count(c)) m[c]++;
    else
      m[c] = 1;
  }

  string first = "", last = "", odd = "";

  for (auto c: m) {
    if (c.second % 2 == 1) {
      if (odd.length() > 0) {
        cout << "NO SOLUTION";
        return 0;
      }
      odd = string(c.second, c.first);
    } else {
      first += string(c.second / 2, c.first);
      last = string(c.second / 2, c.first) + last;
    }
  }

  cout << first + odd + last;

  return 0;
}
