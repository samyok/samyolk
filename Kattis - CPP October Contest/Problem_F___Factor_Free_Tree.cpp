// Kattis Problem F - Factor-Free Tree - 10/8/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>
map<ll, set<ll>> memo;

set<long long> primeFactors(long long n) {
  if(memo.count(n)) return memo[n];
  set<ll> running;
  while (n % 2 == 0) {
    running.insert(2);
    n /= 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      running.insert(i);
      n /= i;
    }
  }
  if(n > 1) running.insert(n);
  memo[n] = running;
  return running;
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n;
  cin >> n;

  ll tmp;
  vl nums;
  for (long long i = 0; i < n; i++) {
    cin >> tmp;
    nums.push_back(tmp);
  }

  set<ll> running;
  vector<ll> ans(n + 1, 0);

  ll prevMode = 0;
  ll prevParent = n;
  while (!nums.empty()) {
    set<ll> pf = primeFactors(nums.back());
    ll goal = running.size() + pf.size();
    running.insert(pf.begin(), pf.end());
    if(running.size() == goal) {
      prevMode = 0;
      ans[prevParent] = nums.size();
      prevParent = nums.size() - 1;
    } else {
      if(prevMode == 1) {
        cout << "impossible";
        return 0;
      }
      prevMode = 1;
      ans[nums.size() - 1] = prevParent + 1;
    }
    nums.pop_back();
  }

  for (long long i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
