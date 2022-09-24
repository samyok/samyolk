/*
ID: samyok1
TASK: main
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

typedef vector<int> vi;
typedef vector<ll> vl;

const ll INF = 1e18;

const int n = 8;
int tree[2 * n];

int query(int a, int b) {
  a += n;
  b += n;
  int ans = 0;
  while (a <= b) {
    if (a % 2 == 1) ans += tree[a++];
    if (b % 2 == 0) ans += tree[b--];
    a /= 2;
    b /= 2;
  }
  return ans;
}

void add(int i, int x){
  i += n;
  tree[i] += x;
  for(i /= 2; i > 1; i /= 2){
    tree[i] = tree[2 * i] + tree[2 * i + 1];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // code here

  int input[n] = {5, 8, 6, 3, 2, 7, 2, 6};

  for (int i = 0; i < n; i++) {
    add(i, input[i]);
  }

  // find sum between 2..4 -- should be 11.
  cout << query(2, 4) << endl;
  cout << "done" << endl;

  return 0;
}
