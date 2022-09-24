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

auto cmp = [](const pair<int, int>& lhs, const pair<int, int>& rhs)
{
  return lhs.first < rhs.first;
};


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // code here

  vector<string> ranks;

  int n, m; cin >> n >> m;

  for(int i = 1; i <= n; i++) {
    ranks.push_back("T" + to_string(i));
  }

  // game
  for (long long i = 0; i < m; i++) {
    string a, b; cin >> a >> b;

    int indexA = std::find(ranks.begin(), ranks.end(), a) - ranks.begin();
    int indexB = std::find(ranks.begin(), ranks.end(), b) - ranks.begin();

    if(indexA > indexB) {
      // 1, 2, 3, 4, 5
      // 4 beats 1 -> [3, 0]
      // 2, 3, 4, 1, 5
      for(int ix = indexB; ix < indexA; ix++){
        ranks[ix] = ranks[ix + 1];
      }
      ranks[indexA] = b;
    }
  }

  for(auto t: ranks) cout << t << " ";

  return 0;
}
