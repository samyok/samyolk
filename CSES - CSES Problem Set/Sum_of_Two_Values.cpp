// CSES Sum of Two Values - 9/24/22

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

  int n, x, tmp;
  map<int, int> m;

  cin >> n >> x;

  for (int i = 0; i < n; i++) {
    cin >> tmp;
    if(m.count(x - tmp)) {
      cout << m[x - tmp] + 1 << " " << i + 1;
      return 0;
    }
    m[tmp] = i;
  }

  cout << "IMPOSSIBLE";
  return 0;
}
