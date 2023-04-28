// Kattis Problem E - Left and Right - 10/8/22

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

  int n; cin >> n;
  string path; cin >> path;
  vector<int> ans(n, 0);
  deque<int> rs, ls;
  rs.push_back(0);
  rs.push_back(0);
  for(int i = 0; i < path.size(); i++){
    if(path[i] == 'R') {
      rs.push_back(i + 1);
    } else {
      ls.push_back(i + 1);
    }
  }

  int prev = n;
  while(!rs.empty()){
    for(int i = rs.back(); i < prev; i++){
      ans[i] = n--;
    }
    prev = rs.back();
    rs.pop_back();
  }

  for(auto a: ans) cout << a << "\n";

  return 0;
}
