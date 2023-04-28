//  Distinct Numbers

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  set<int> s;
  int n; cin >> n;
  int tmp;
  for (long long i = 0; i < n; i++) {
    cin >> tmp;
    s.insert(tmp);
  }
  cout << s.size();
  return 0;
}
