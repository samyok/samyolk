#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// move n from A to B

string res = "\n";

ll turns = 0;

// ABC is 1,2,3

void move(int n, int a, int b) {
  // base case: n = 1:
  if (n == 1) {
    res += to_string(a) + " " + to_string(b) + "\n";
    turns++;
    return;
  }

  int c = 6 - a - b;

  // we have to move n - 1 from A -> C
  move(n -1, a, c);
  // then we move 1 from A -> B
  move(1, a, b);
  // then we move n - 1 from C -> B
  move(n -1, c, b);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // code here

  int n; cin >> n;
  move(n, 1, 3);
  cout << turns << res;

  return 0;
}
