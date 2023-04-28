// Kattis Problem D - ICPC Team Selection - 1/18/23

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>


void solve() {

  int n; cin >> n;
  vi team;
  int tmp;
  for (long long i = 0; i < 3 * n; i++) {
    cin >> tmp;
    team.push_back(tmp);
  }
  sort(team.begin(), team.end());
  int sum = 0;
  for (long long i = 0; i < n; i++) {
    team.pop_back();
    sum += team.back();
    team.pop_back();
  }
  cout << sum << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  unordered_map<string, vector<string>> adj;
  string x;
  getline(cin, x);


  for (long long i = 0; i < n; i++) {
    string s;
    getline(cin, s);
    string word = "";
    vector<string> words;
    for(char c: s){
      if(c == ' '){
        words.push_back(word);
        word = "";
      } else {
        word += c;
      }
    }
    words.push_back(word);

    string start = words.front();
    for(int w = 1; w < words.size(); w++){
      adj[start].push_back(words[w]);
      adj[words[w]].push_back(start);
    }
  }

  string a, b;
  cin >> a >> b;

//  cout << "find from " << a << b << endl;
  // dfs through to see path
  stack<pair<string, vector<string>>> dfs;
  dfs.push({a, {a}});
  while(!dfs.empty()){
    auto [cur, path] = dfs.top();
    dfs.pop();

    for(auto nx: adj[cur]){
      if(nx == b) {
        for(auto p : path){
          cout << p << " ";
        }
        cout << nx;
        return 0;
      }
      if(find(path.begin(), path.end(), nx) == path.end()){
        vector<string> nv(path);
        nv.push_back(nx);
        dfs.push({nx, nv});
      }
    }
  }
  cout << "no route found";

  return 0;
}
