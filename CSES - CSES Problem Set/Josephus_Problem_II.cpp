// CSES Josephus Problem II - 9/24/22

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

  int n, k;
  cin >> n >> k;
  k++;

  vector<int> nums;

  for (int i = 1; i <= n; i++){
    if(i % k == 0) cout << i << " ";
    else nums.push_back(i);
  }

  int next = n % k;
  if(k >= n) next = (k - 1) % n;

  while (nums.size() > 1) {
    cout << nums[next] << " ";
    nums.erase(nums.begin() + next);

    next += k - 1;
    next %= nums.size();
  }

  if(nums.size() > 0) cout << nums[0];

  return 0;
}
