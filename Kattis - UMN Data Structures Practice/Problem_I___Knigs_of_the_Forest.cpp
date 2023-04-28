// Kattis Problem I - Knigs of the Forest - 10/5/22

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

  ll k, n;
  cin >> k >> n;

  priority_queue<ll> h;

  pair<ll, ll> karl;

  unordered_map<ll, ll> a;

  ll year, strength;
  for (long long i = 0; i < n + k - 1; i++) {
    cin >> year >> strength;
    if(i == 0)  karl = {year + 0, strength + 0};
    if(year == 2011) h.push(strength);
    else a[year] = strength;
  }


  ll curYear = 2011;

  while(h.top() != karl.second) {
    h.pop();
    if(!a.count(++curYear)) {
      cout << "unknown";
      return 0;
    }
    h.push(a[curYear]);
  }

  cout << curYear;

  return 0;
}
