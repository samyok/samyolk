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

unordered_map<string, string> uf;

string find(string a){
  if(uf.count(a) && uf[a] != a) uf[a] = find(uf[a]);
  else uf[a] = a;

  return uf[a];
}


void merge(string a, string b) {
  uf[find(a)] = find(b);
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

  return 0;
}
