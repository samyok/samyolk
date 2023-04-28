// Kattis Problem A - Alien Numbers - 10/29/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

void solve(){
  string a, b, c;
  cin >> a >> b >> c;
  map<char, int> source;
  for(int i = 0; i < b.size(); i++) source[b[i]] = i;

  long long m = 0;
  for(char x: a) {
    m *= b.size();
    m += source[x];
  }
  vector<int> ans;
  while(m > 0) {
    ans.push_back(m % c.size());
    m /= c.size();
  }

  for(int i = ans.size() - 1; i>=0; i--){
    cout << c[ans[i]];
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T; cin >> T;
  for (long long i = 0; i < T; i++) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }

  return 0;
}
