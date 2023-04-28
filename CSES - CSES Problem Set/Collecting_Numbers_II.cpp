// CSES Collecting Numbers II - 9/24/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

// maintain a map of who is before and who isn't
const int N = 2e5 + 1;
unordered_map<int, int> mp;
vector<int> v;
bool hasBefore[N];

int rounds = 1;

void update(int n) {
  bool shouldBe = mp[n - 1] < mp[n];
  if (hasBefore[n] != shouldBe) {
    hasBefore[n] = shouldBe;
    if (shouldBe) rounds--;
    else
      rounds++;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  // init with 0
  v.push_back(0);
  mp[0] = 0;
  hasBefore[0] = true;

  int n, m, t;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> t;
    if (mp.count(t - 1) == 0) {
      rounds++;
      hasBefore[t] = false;
    } else {
      hasBefore[t] = true;
    }

    v.push_back(t);
    mp[t] = i;
  }

  for (long long i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    mp[v[a]] = b;
    mp[v[b]] = a;
    swap(v[a], v[b]);
    for (int d = -1; d <= 1; d++) {
      if (v[a] + d <= n && v[a] + d > 0) update(v[a] + d);
      if (v[b] + d <= n && v[b] + d > 0) update(v[b] + d);
    }
    cout << rounds << "\n";
  }

  return 0;
}
