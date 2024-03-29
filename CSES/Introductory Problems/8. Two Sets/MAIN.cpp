/* 
ID: samyok1
TASK: MAIN
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, wsum, sum=0, px = 1;
    cin >> n;
    vl x;
    if (n * (n + 1) % 4 != 0) {
        cout << "NO";
        return 0;
    }
    wsum = n * (n + 1) / 4;
    if(wsum % n == 0){
        x.pb(n);
        sum += n;
    }
    while (wsum != sum) {
        if(wsum % n == 0){
            x.pb(n-px);
            x.pb(px);
            sum += n;
        } else {
            x.pb(n-px +1);
            x.pb(px);
            sum += n + 1;
        }
        px++;
    }
    sort(all(x));
    px=0;
    string y;
    cout << "YES\n" << x.size() << "\n";
    for (ll i = 1; i <=n; i++) {
        if(px < x.size() && x[px] == i) {
            cout << i << " ";
            px++;
        } else {
            y += to_string(i) + " ";
        }
    }
    cout << "\n" << n-x.size() << "\n" << y;
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343 and iNum
// used by techguy2
// functions go before int main() silly
