// Codeforces C. Minimum Notation - 9/25/22

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

  int tests;
  cin >> tests;
  for (long long i = 0; i < tests; i++) {
    string s; cin >> s;
    map<int, int> m;
    stack<int> cur;
    for(char c: s) {
      while(!cur.empty() && cur.top() > c - '0') {
        m[min(cur.top() + 1, 9)]++;
        cur.pop();
      }
      cur.push(c - '0');
    }

    while(!cur.empty()) {
      m[cur.top()]++;
      cur.pop();
    }
    for(auto [key, value]: m){
      for(int v = 0; v < value; v++) {
        cout << key;
      }
    }
    cout << "\n";
  }


  return 0;
}
