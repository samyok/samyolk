// Kattis Problem F - Sim - 10/6/22

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

  deque<char> text;
  string ondeck = "";

  int tests;
  cin >> tests;
  cin.ignore();

  for (long long i = 0; i < tests; i++) {
    string line;
    getline(cin, line);
    bool modeAddToStart = false;
    text.clear();
    ondeck = "";
    for (char c: line) {
      if (c == '[') {
        modeAddToStart = true;
        for (int o = ondeck.size() - 1; o >= 0; o--) text.push_front(ondeck[o]);
        ondeck = "";
        continue;
      }

      if (c == ']') {
        // add stuff to front
        for (int o = ondeck.size() - 1; o >= 0; o--) text.push_front(ondeck[o]);
        ondeck = "";
        modeAddToStart = false;
        continue;
      }

      if (c == '<') {
        if (modeAddToStart && !ondeck.empty()) ondeck.pop_back();
        if (!modeAddToStart && !text.empty()) text.pop_back();
        continue;
      }

      if (modeAddToStart) ondeck += c;
      else
        text.push_back(c);
    }

    if (modeAddToStart) {
      for (int o = ondeck.size() - 1; o >= 0; o--) text.push_front(ondeck[o]);
    }

    for (char c: text) {
      cout << c;
    }
    cout << "\n";
  }

  return 0;
}
