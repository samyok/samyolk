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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // code here

  int n;
  cin >> n;

  set<ll> nums;
  nums.insert(0);

  for (long long i = 0; i < n; i++) {
    ll x;
    cin >> x;
    for(ll xi : nums){
      nums.insert(x + xi);
    }
  }

  for (long long i = 0; i < INF; i++) {
    if(nums.count(i)) {
      cout << i;
      return 0;
    }
  }

  return 0;
}
