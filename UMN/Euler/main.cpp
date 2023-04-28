// Kattis Arrangement - 9/26/22

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

  long N = 600851475143;

  int n = (int)pow(N, 0.5) + 1;

  vector<bool> is_prime(n+1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
    }
  }


  for(int i = n; i >= 1; i--){
    if(N % i == 0 && is_prime[i] ) {
      cout << i << endl;
      return 0;
    }
  }

  cout << "no";
  return 0;
}
