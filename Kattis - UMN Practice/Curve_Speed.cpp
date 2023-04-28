// Kattis Curve Speed - 1/18/23

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

void solve() {
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);


    double r, s;

    while(cin >> r >> s){
      double V = sqrt(r * (s +0.16) / 0.067);
      cout << round(V) << endl;
    }


  return 0;
}
