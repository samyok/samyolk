// Kattis Problem C - Engineering English - 10/6/22

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

  string line;
  set<string> dict;

  string word = "", lowerCase = "";

  while(getline(cin, line)){
    for(char c: line) {
      if(c == ' ') {
        if(dict.count(lowerCase)) cout << ". ";
        else cout << word << " ";
        dict.insert(lowerCase);
        word = "";
        lowerCase = "";
      } else {
        word += c;
        lowerCase += tolower(c);
      }
    }
    if(dict.count(lowerCase)) cout << ". ";
    else cout << word << " ";
    dict.insert(lowerCase);
    word = "";
    lowerCase = "";

    cout << "\n";
  }

  return 0;
}
