// CSES Movie Festival - 9/24/22

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

  vector<pi> movies;

  int start, end;
  for (long long i = 0; i < n; i++) {
    cin >> start >> end;
    movies.push_back({end, start});
  }

  sort(movies.begin(), movies.end());

  int cur = movies[0].first, ans = 1;

  for(auto mv: movies){
    if(mv.second >= cur) {
      ans++;
      cur = mv.first;
    }
  }

  cout << ans;
  return 0;
}
