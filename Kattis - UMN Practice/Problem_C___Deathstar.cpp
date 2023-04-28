// Kattis Problem C - Deathstar - 1/18/23

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

  ll n; cin >> n;

  vector<vi> b;

  for (long long i = 0; i < n; i++) {
    vi t;
    int a = 0;
    for (long long j = 0; j < n; j++) {
      int tmp; cin >> tmp;
      if(j != i) a |= tmp;
    }
    cout << a << " ";
  }

  return 0;
}
