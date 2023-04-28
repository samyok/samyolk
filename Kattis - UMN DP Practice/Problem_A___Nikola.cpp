// Kattis Problem A - Nikola - 10/10/22

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

  vector<int> cost;
  int tmp;
  for (long long i = 0; i < n; i++) {
    cin >> tmp;
    cost.push_back(tmp);
  }

  vector<vector<int>> dp(n, vector<int>(n, 1000000));

  dp[0][0] = 0;


  int ans = INT_MAX;
  for(int row = 1; row < n; row++){
    for(int col = n - 1; col >= 0; col--){
      if(col + row < n) dp[row][col] = min(dp[row][col], dp[row][col + row] + cost[col]);
      if(col - row >= 0) dp[row][col] = min(dp[row][col], dp[row - 1][col - row] +  cost[col]);
    }
    ans = min(ans, dp[row].back());
  }


//  for (long long i = 0; i < n; i++) {
//    for (long long j = 0; j < n; j++) {
//      if(dp[i][j] < INT_MAX) cout << dp[i][j] << " ";
//      else cout << "X ";
//    }
//    cout << "\n";
//  }
  cout << ans;
  return 0;
}
