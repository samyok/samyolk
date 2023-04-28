// Kattis Problem D - Grandpa Bernie - 10/6/22

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

  unordered_map<string, vector<int>> m;
  ll n;
  cin >> n;
  string country;
  int year;

  for (long long i = 0; i < n; i++) {
    cin >> country >> year;
    m[country].push_back(year);
  }

  for(auto &[countryKey, years] : m){
    std::sort(years.begin(), years.end());
  }

  cin >> n;
  int number;
  for (long long i = 0; i < n; i++) {
    cin >> country >> number;
    cout << m[country][number - 1] << "\n"  ;
  }

  return 0;
}
