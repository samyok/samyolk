// AtCoder A - Frog 1 - 3/22/23

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

const int MAXN = 1e5 + 5;
int dp[MAXN], h[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (long long i = 0; i < N; i++) cin >> h[i];

  // jumps to get to N
  dp[0] = 0;

  // set DP to max:
  for (long long i = 1; i < N; i++) dp[i] = INT32_MAX;


  for (long long i = 0; i < N; i++) {
    dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
    dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
  }


  cout << dp[N - 1];
  return 0;
}
