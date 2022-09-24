#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string pad(string s, int n) {
  s.insert(s.begin(), n - s.length(), '0');
  return s;
}

void padPrint(string s, int n) {
  s = pad(s, n);
  cout << s << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<string> r;
  r.emplace_back("0");
  padPrint("0", n);

  r.emplace_back("1");
  padPrint("1", n);

  for (long long i = 1; i < n; i++) {
    ll curSize = r.size();
    for (long long j = 0; j < curSize; j++) {
      string newNum = "1" + pad(r[curSize - 1 - j], i);
      r.emplace_back(newNum);
      padPrint(newNum, n);
    }
  }

  return 0;
}
