// USACO Problem 2. Sleepy Cow Sorting - 4/12/23

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>


class ST {
  int num;
  int tree[];

  void add(int i, int val) {
    tree[]
  }
};


const int MAXN = 1e5;
int cows[MAXN + 1];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (long long i = 0; i < N; i++) {
    cin >> cows[i];
  }

  int boundary = 1;

  for (long long i = N - 1; i >= 0; i--) {
    if (cows[i - 1] < cows[i]) boundary++;
    else
      break;
  }


  return 0;
}
