// CSES Missing Coin Sum - 9/24/22

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
  ll n, tmp;
  cin >> n;
  vl coins;
  for (long long i = 0; i < n; i++) {
    cin >> tmp;
    coins.push_back(tmp);
  }

  sort(coins.begin(), coins.end());

  ll cur = 1;

  //     1    3    3     7    9
  //  1  2    

  for(ll c: coins){
    if(cur >= c) cur += c;
    else {
      cout << cur;
      return 0;
    }
  }

  cout << cur;
  return 0;
}
