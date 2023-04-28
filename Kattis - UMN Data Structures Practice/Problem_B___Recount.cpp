// Kattis Problem B - Recount - 10/5/22

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

  map<string, ll> m;

  string name, mxn = "";

  ll n = 0;

  while(getline(cin, name)){
    if(name == "***") break;
    m[name]++;
    n++;
  }


  ll mx = 0;
  for(auto [k, v]: m){
    if(v > mx) {
      mxn = k;
      mx = v;
    } else if(v == mx) mxn = "Runoff!";
  }

  cout << mxn;

  return 0;
}
