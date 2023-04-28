// Kattis Problem C - Cheaper Drink - 3/18/23

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

void solve() {
}

string flipped(string s) {
  map<char, char> m = {
    {'0', '0'},
    {'1', '1'},
//    {'2', '5'},
//    {'5', '2'},
    {'8', '8'},
    {'6', '9'},
    {'9', '6'}
  };

  // see if all the numbers are flippable
  for (char c : s) {
    if (m.find(c) == m.end()) {
      return s;
    }
  }

  // flip the numbers
  string flipped = "";
  for (int i = s.size() - 1; i >= 0; i--) {
    flipped += m[s[i]];
  }

  int x = stoi(flipped), y = stoi(s);
  if(x < y) {
    return flipped;
  } else {
    return s;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n;
  vector<string> nums;
  for (long long i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    nums.push_back(flipped(tmp));
    cout << flipped(tmp) << endl;
  }

  sort(nums.begin(), nums.end());
  for(auto a : nums) {
    cout << a << endl;
  }
  return 0;
}
