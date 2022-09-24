#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll p(ll b, ll e) {
  if (e == 0) return 1;
  return b * p(b, e - 1);
}

char digit_query(ll k) {
  // 10^n -> 10^n+1 - 1 = n * 9 * 10^n digits

  // find the power of 10 that we start with
  ll power = 0;
  while (k > 9 * (power + 1) * p(10, power))
    k -= (power + 1) * 9 * p(10, power++);

  // we now have to find the kth digit after 10^power

  // 3 is the 12th digit in 100101102103 -- ie the 11/3 = 3th num, 11%3 = 2 ==> 3rd digit
  // the 14th digit: 13/3 = 4 (in 104), 13%3 = 1 ==> 2nd digit (0)

  ll digits = power + 1;
  k--;
  ll number = p(10, power) + (k / digits);
  return to_string(number)[k % digits];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    ll k;
    cin >> k;
    cout << digit_query(k) << "\n";
  }

  return 0;
}
