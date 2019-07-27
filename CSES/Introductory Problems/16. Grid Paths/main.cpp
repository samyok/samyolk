/* 
ID: samyok1
TASK: main
LANG: C++11
*/
// Template.cpp last updated 6/7/18
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
// change these numbers
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

ll w = 0, steps = 0;
bool v[7][7];
int reserved[49];

void solve(ll r, ll c) {
    if (r == 6 && c == 0) {
        if (steps == 48) w++;
        return;
    }
    bool t = v[r][c] || (
            (
                    c > 0 && c < 6 && !v[r][c + 1] && !v[r][c - 1] &&
                    ((r == 0 && v[r + 1][c]) || (r == 6 && v[r - 1][c]))) || (
                    r > 0 && r < 6 && !v[r + 1][c] && !v[r - 1][c] &&
                    ((c == 0 && v[r][c + 1]) || (c == 6 && v[r][c - 1]))))
             || (r > 0 && r < 6 && c > 0 && c < 6 && v[r - 1][c] && v[r + 1][c] && !v[r][c - 1] && !v[r][c + 1])
             || (r > 0 && r < 6 && c > 0 && c < 6 && v[r][c - 1] && v[r][c + 1] && !v[r - 1][c] && !v[r + 1][c]);
    if (t) return;
    v[r][c] = true;
    if (reserved[steps] != -1) {

        switch (reserved[steps]) {
            case 0:
                if (r > 0 && !v[r - 1][c]) {
                    steps++;
                    solve(r - 1, c);
                    steps--;
                }
                break;
            case 2:
                if (r < 6 && !v[r + 1][c]) {
                    steps++;
                    solve(r + 1, c);
                    steps--;
                }
                break;
            case 3:
                if (c > 0 && !v[r][c - 1]) {
                    steps++;
                    solve(r, c - 1);
                    steps--;
                }
                break;
            case 1:
                if (c < 6 && !v[r][c + 1]) {
                    steps++;
                    solve(r, c + 1);
                    steps--;
                }
                break;

        }
        v[r][c] = false;

        return;
    }
    if (r > 0 && !v[r - 1][c]) {
        steps++;
        solve(r - 1, c);
        steps--;
    }
    if (r < 6 && !v[r + 1][c]) {
        steps++;
        solve(r + 1, c);
        steps--;
    }
    if (c > 0 && !v[r][c - 1]) {
        steps++;
        solve(r, c - 1);
        steps--;
    }
    if (c < 6 && !v[r][c + 1]) {
        steps++;
        solve(r, c + 1);
        steps--;
    }
    v[r][c] = false;
}

int main() {
//    auto start = chrono::steady_clock::now();

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '?') reserved[i] = -1;
        else if (str[i] == 'U') reserved[i] = 0;
        else if (str[i] == 'R') reserved[i] = 1;
        else if (str[i] == 'D') reserved[i] = 2;
        else if (str[i] == 'L') reserved[i] = 3;
    }
    solve(0, 0);
    cout << w;
//    auto end = chrono::steady_clock::now();
//    cout << "\nElapsed time in milliseconds : "
//         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
//         << " ms\n";
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343 and iNum
// used by techguy2
// functions go before int main() silly
