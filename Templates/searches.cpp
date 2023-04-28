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

// some cost function that we're trying to optimize
long long cost(vector<int> &nums, vector<int> &c, long long eq) {
  long long ans = 0;
  for (long long i = 0; i < nums.size(); i++) ans += abs(nums[i] - eq) * c[i];
  return ans;
}

// binary search on a slope
long long minCost(vector<int> &nums, vector<int> &c) {
  int hi = 1e6 + 1, lo = 0;
  while (hi > lo) {
    int mid = (hi + lo) / 2;
    if (cost(nums, c, mid) > cost(nums, c, mid + 1)) lo = mid + 1;
    else
      hi = mid;
  }
  return cost(nums, c, lo);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // code here


  return 0;
}
