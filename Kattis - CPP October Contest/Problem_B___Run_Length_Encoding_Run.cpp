// Kattis Problem B - Run-Length Encoding, Run! - 10/8/22

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

  string mode, text;
  cin >> mode >> text;

  if(mode == "E") {
    char cur = text[0];
    int num = 1;
    for(int i = 1; i < text.size(); i++){
      if(cur != text[i]) {
        cout << cur << num;
        cur = text[i];
        num = 1;
      } else {
        num++;
      }
    }
    cout << cur << num;

    return 0;
  }

  int a = 0;
  char t;
  for(char c: text){
    if((++a) % 2 == 1) {
      t = c;
    } else {
      for(int i = 0; i < c - '0'; i++){
        cout << t;
      }
    }
  }
  return 0;
}
