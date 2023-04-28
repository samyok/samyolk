// Kattis Problem D - Costume Contest - 10/29/22

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
  map<string, int> freq;
  string s;
  for (long long i = 0; i < n; i++) {
    cin >> s;
    freq[s]++;
  }

  int mn = INT_MAX;
  vector<string> mns;

  for(auto [key, value]: freq) {
    if(value < mn){
      mns.clear();
      mn = value;
    }
    if(value == mn) mns.push_back(key);
  }
  for(string x: mns) cout << x << endl;
  return 0;
}
