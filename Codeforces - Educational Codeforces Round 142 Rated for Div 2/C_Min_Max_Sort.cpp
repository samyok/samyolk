// Codeforces C. Min Max Sort - 1/24/23

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>

// Returns inversion count in arr[0..n-1]
int getInvCount(vi arr, int n) {
  // Create an empty set and insert first element in it
  multiset<int> set1;
  set1.insert(arr[0]);

  int invcount = 0;// Initialize result

  multiset<int>::iterator itset1;// Iterator for the set

  // Traverse all elements starting from second
  for (int i = 1; i < n; i++) {
    // Insert arr[i] in set (Note that set maintains
    // sorted order)
    set1.insert(arr[i]);

    // Set the iterator to first greater element than arr[i]
    // in set (Note that set stores arr[0],.., arr[i-1]
    itset1 = set1.upper_bound(arr[i]);

    // Get distance of first greater element from end
    // and this distance is count of greater elements
    // on left side of arr[i]
    invcount += distance(itset1, set1.end());
  }

  return invcount;
}


void solve() {
  int n;
  cin >> n;
  vi a(n);
  vi index(n + 1, n + 2);
  index[0] = -1;
  for (int i = 0; i < n; i++) cin >> a[i];
  //  int ans = min(tooo, looo);
  //  ans += tooo + looo - 2 * ans;
  cout << min(getInvCount(a, n)/2, n/2) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  cin >> T;
  while (T--) solve();


  return 0;
}
