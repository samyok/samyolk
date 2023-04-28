// Codeforces D. Coprime - 10/13/22

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


void solve() {
  int n;
  cin >> n;
  int tmp;
  vector<set<ll>> nums;
  for (long long j = 0; j < n; j++) {
    cin >> tmp;
    nums.push_back(primeFactors(tmp));
  }

  for (int a = nums.size() - 1; a >= 0; a--) {
    for (int b = nums.size() - 1; b >= a; b--) {
      // see if there's overlap very quickly:
      set<ll> cur(nums[a].begin(), nums[a].end());
      cur.insert(nums[b].begin(), nums[b].end());

      if(cur.size() == nums[a].size() + nums[b].size()) {
        cout << a + b + 2 << "\n";
        return;
      }
    }
  }
  cout << "-1\n";
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }

  return 0;
}