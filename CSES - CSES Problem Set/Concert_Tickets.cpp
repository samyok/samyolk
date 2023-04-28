// CSES Concert Tickets - 9/24/22

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

  int n, m, tmp;
  cin >> n >> m;
  map<int, int> tkts;
  for (long long i = 0; i < n; i++) {
    cin >> tmp;
    tkts[tmp]++;
  }

  for (long long i = 0; i < m; i++) {
    cin >> tmp;
    auto it = tkts.upper_bound(tmp);
    if(it == tkts.begin()) cout << "-1\n";
//    else {
//      it--;
//      it->second--;
//      if(it->second <= 0) tkts.erase(it);
//      cout << it->first << "\n";
//    }
  }

  return 0;
}
