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
  vector<int> times;
  int maxRequests, windowFrame;

  // actual code
  vector<bool> ans;
  queue<int> wait;
  for(int n: times) {
    while(!wait.empty() && wait.front() < n - windowFrame) wait.pop();

    if(wait.size() < maxRequests) {
      ans.push_back(true);
      wait.push(n);
    } else {
      ans.push_back(false);
    }
  }
  return ans;

  return 0;
}






