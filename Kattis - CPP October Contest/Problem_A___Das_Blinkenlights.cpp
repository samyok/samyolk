// Kattis Problem A - Das Blinkenlights - 10/8/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>
int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int p, q, s;
  cin >> p >> q >> s;
  if(p * q / gcd(p, q) <= s) cout << "yes";
  else cout << "no";

  return 0;
}
