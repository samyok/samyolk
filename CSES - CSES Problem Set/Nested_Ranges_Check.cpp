// CSES Nested Ranges Check - 9/24/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

const int N = 2e5 + 1;
bool containing[N], contained[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  deque<pi> fwd;

  int n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;
    fwd.emplace_back(end, start);
  }

  sort(fwd.begin(), fwd.end());

  // pop forward until end time > this end time, mark all of those as contained
  int num = 0;
  while(!fwd.empty()) {
    auto [end, start] = fwd.front();
    fwd.pop_front();
    while(!fwd.empty() && end > fwd.front().second) {
      num++;
      cout << "is contained: " << fwd.front().second << " " << fwd.front().first << "\n"
      fwd.pop_front();
    }
  }
  cout << num << endl;
  return 0;
}
