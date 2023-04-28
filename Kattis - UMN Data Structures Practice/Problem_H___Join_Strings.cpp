// Kattis Problem H - Join Strings - 10/6/22

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

  ll n; cin >> n;

  string tmp;
  unordered_map<long long, string> v;
  for (long long i = 0; i < n; i++) {
    cin >> tmp;
    v[i + 1] = tmp;
  }

  ll a, b;
  for (long long i = 0; i < n - 1; i++) {
    cin >> a >> b;
    v[a] += v[b];
    v[b] = "";
  }

  for(auto &[k, s]: v){
    if(s.empty()) continue;
    cout << s;
    return 0;
  }
  return 0;
}
