// Codeforces A. Number Replacement - 11/13/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

void solve(){
  int n;
  cin >> n;

  // for each letter, we have to make sure that every other one in that uf is also the same letter
  map<int, vi> where;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    int tmp; cin >> tmp;
    where[tmp].push_back(i);
    nums.push_back(tmp);
  }
  string s;
  cin >> s;
  for(int i = 0; i <s.size(); i++){
    // make sure that every letter in where is valid
    for(int a: where[nums[i]]){
      if(s[i] != s[a]){
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }


  return 0;
}
