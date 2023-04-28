// Kattis Problem C - Dunglish - 10/8/22

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<ll, ll>
#define vl vector<ll>
#define vi vector<ll>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n;
  cin >> n;
  unordered_map<string, ll> words;
  string tmp;
  vector<string> og;
  for (long long i = 0; i < n; i++) {
    cin >> tmp;
    words[tmp]++;
    og.push_back(tmp);
  }

  ll m;
  cin >> m;

  unordered_map<string, ll> correct, incorrect;
  unordered_map<string, string> dict;
  string d, e, c;
  for (long long i = 0; i < m; i++) {
    cin >> d >> e >> c;
    if (c == "correct") correct[d]++;
    else
      incorrect[d]++;
    dict[d] = e;
  }
  ll cor = 1, total = 1;
  for (auto [word, value]: words) {
    for (long long i = 0; i < value; i++) {
      cor *= correct[word];
      total *= correct[word] + incorrect[word];
    }
  }

  ll incor = total - cor;
  if (cor == 1 || incor == 1) {
    for (auto w: og) {
      cout << dict[w] << " ";
    }
    cout << "\n";
    if (incor == 1) cout << "incorrect\n";
    else
      cout << "correct\n";
    return 0;
  }
  cout << cor << " correct\n";
  cout << incor << " incorrect\n";

  return 0;
}
