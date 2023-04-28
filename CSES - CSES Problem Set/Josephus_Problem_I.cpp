// CSES Josephus Problem I - 9/24/22

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

  int n;
  cin >> n;

  vector<int> nums;
  for (int i = 1; i <= n; i++){
    if(i % 2 == 0) cout << i << " ";
    else nums.push_back(i);
  }

  int next = (n % 2 == 0);

  while (nums.size() > 1) {
    cout << nums[next] << " ";
    nums.erase(nums.begin() + next);

    next++;
    if (next >= nums.size()) next -= nums.size();
  }

  cout << nums[0];
  return 0;
}
