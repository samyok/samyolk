// Codeforces A. Hayato and School - 1/25/23

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>
#define vpi vector<pi>

void solve() {
  int n; cin >> n;
  vi odds, evens;
  if(n < 3){
    cout << "NO" << "\n";
    return;
  }
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    if(x % 2 == 0) evens.push_back(i + 1);
    else odds.push_back(i + 1);
  }

  if(odds.size() == 0) {
    cout << "NO" << "\n";
    return;
  }

  if (odds.size() >= 3) {
    cout << "YES\n";
    cout << odds[0] << " " << odds[1] << " " << odds[2] << "\n";
    return;
  } else if(evens.size() >= 2){
    cout << "YES\n";
    cout << evens[0] << " " << evens[1] << " " << odds[0] << "\n";
    return;
  } else {
    cout << "NO" << "\n";
    return;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  cin >> T;
  while (T--) solve();


  return 0;
}
