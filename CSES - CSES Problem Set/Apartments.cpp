//  Restaurant Customers

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  map<int, int> m;
  for(int i = 0; i < n; i++){
    int start, end; cin >> start >> end;
    m[start]++;
    m[end]--;
  }

  int cur = 0, mx = 0;

  for(auto [key, value]: m){
    cur += value;
    mx = max(mx, cur);
  }

  cout << mx;
  return 0;
}
