// Kattis Problem B - This Ain't Your Grandpa's Checkerboard - 1/18/23

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

void solve() {
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n;
  cin >> n;

  if(n % 2 == 1) {
    cout << 0 << endl;
    return 0;
  }

  int x = n / 2;

  vector<string> board;

  for (long long i = 0; i < n; i++) {
    string tmp ; cin >> tmp;
    board.push_back(tmp);

    int b = 0, w = 0;

    char prev = 'a';
    int times = 1;

    for (long long j = 0; j < n; j++) {
      if(tmp[j] == 'W') w++;
      else b++;
      if(tmp[j] == prev) times ++;
      else {
        prev = tmp[j];
        times = 1;
      }

      if(times == 3){
        cout << 0;
        return 0;
      }
    }

    if(b != x || w != x) {
      cout << 0 << endl;
      return 0;
    }
  }


  for (long long c = 0; c < n; c++) {
    int w = 0, b = 0;

    char prev = 'a';
    int times = 1;

    for (long long r = 0; r < n; r++) {
      if(board[r][c] == 'W') w++;
      else b++;

      if(prev == board[r][c]) times++;
      else {
        prev = board[r][c];
        times = 1;
      }
      if(times == 3){
        cout << 0 << endl;
        return 0;
      }
    }
    if(b != x || w != x) {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << 1;
  return 0;
}
