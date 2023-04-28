// Kattis Problem A - Drinking Song - 3/18/23

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

void solve() {
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  cin >> T;

  string s;
  cin >> s;

  for (long long i = T; i >= 1; i--) {
    if (i == 2) {
      cout << i << " bottles of " << s << " on the wall, " << i << " bottles of " << s << ".\nTake one down, pass it around, " << (i - 1) << " bottle of " << s << " on the wall.\n" << endl;

    } else if (i == 1) {
      cout << i << " bottle of " << s << " on the wall, " << i << " bottle of " << s << ".\nTake it down, pass it around, no more bottles of " << s << "." << endl;

    } else {
      cout << i << " bottles of " << s << " on the wall, " << i << " bottles of " << s << ".\nTake one down, pass it around, " << (i - 1) << " bottles of " << s << " on the wall.\n" << endl;
    }
  }


  return 0;
}
