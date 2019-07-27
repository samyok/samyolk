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
typedef complex <ld> cd;

typedef pair<int, int> pi;
typedef pair <ll, ll> pl;
typedef pair <ld, ld> pd;

typedef vector<int> vi;
typedef vector <ld> vd;
typedef vector <ll> vl;
typedef vector <pi> vpi;
typedef vector <pl> vpl;
typedef vector <cd> vcd;

template<class T> using Tree = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

ll ways;
bool col[16], diag1[16], diag2[16], reserved[8][8];

void search(ll r){
    if(r == 8){
        ways ++;
        return;
    }
    for(ll c = 0; c<8; c++){
        if(col[c] || diag1[r+c] || diag2[r-c+7] || reserved[r][c])
            continue;
        col[c] = diag1[r+c] = diag2[r-c+7] = true;
        search(r+1);
        col[c] = diag1[r+c] = diag2[r-c+7] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 16; ++i) {
        col[i] = diag1[i] = diag2[i] = false;
    }
    string x;
    for (int j = 0; j < 8; j++) {
        cin >> x;
        for (int k = 0; k < 8; k++) {
            reserved[j][k] = x[k] != '.';
        }
    }
    search(0);

    cout << ways;
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343 and iNum
// used by techguy2
// functions go before int main() silly
