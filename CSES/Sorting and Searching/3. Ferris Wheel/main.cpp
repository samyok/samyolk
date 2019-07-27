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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, x, t, cg=0, a=0;
    cin >> n >> x;
    multiset<ll> p;
    for (ll i = 0; i < n; ++i) {
        cin >>t;
        p.insert(t);
    }
    while(!p.empty()){
        if(cg == 0){
            a++;
            cg = x- *p.begin();
            p.erase(p.begin());
        } else{
            auto pit = p.lower_bound(cg);
            if(pit == p.begin() && *pit > cg){
                cg = x - *pit;
                a++;
                p.erase(pit);
                continue;
            }
            if(pit == p.end() || *pit > cg){
                pit--;
            }
            p.erase(pit);
            cg=0;
        }
    }
    cout << a;
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343 and iNum
// used by techguy2
// functions go before int main() silly
