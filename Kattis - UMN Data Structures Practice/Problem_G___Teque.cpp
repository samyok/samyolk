// Kattis Problem G - Teque - 10/6/22

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

  deque<ll> front, back;

  ll n;
  cin >> n;
  string method;
  ll num;

  for (long long i = 0; i < n; i++) {
    cin >> method >> num;

    if (method == "push_front") front.push_front(num);
    else if (method == "push_back")
      back.push_back(num);
    else if (method == "push_middle") {
      front.push_back(num);
    } else {
      // get
      if (num < front.size()) cout << front[num];
      else cout << back[num - front.size()];
      cout << "\n";

    }

    // see if the front/back are unbalenced, front should be equal or 1 less than back
    while (front.size() > back.size()) {
      back.push_front(front.back());
      front.pop_back();
    }

    while (back.size() > front.size()) {
      front.push_back(back.front());
      back.pop_front();
    }
  }

  return 0;
}
