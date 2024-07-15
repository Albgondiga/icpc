#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define pf push_front
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef pair<ll,ll> pll;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 1
#define ifd if (debug)

const ll INF = 1e9;
const ll MOD = 1e9+7;
const ll mxX = 1e6+5;
ll value[mxX]; 
ll ready[mxX];
vector<ll> coins;

// Iterativo
void solveI(ll n) {
    value[0] = 0;
    for (ll x = 1; x <= n; x++) {
        value[x] = INF;
        for (auto c : coins) {
            if (x-c >= 0) {
                value[x] = min(value[x], value[x-c]+1);
            }
        }
    }
}

// Recursivo
ll solveR(ll x) {
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (ready[x]) return value[x];

    ll best = INF;
    for (auto c : coins) {
        best = min(best, solveR(x-c)+1);
    }

    ready[x] = 1;
    value[x] = best;
    return value[x];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    memset(ready, 0, sizeof(ready));

    ll n; cin>>n;
    ll x; cin>>x;
    coins.resize(n);
    forn (i, n) cin>>coins[i];

    //solveI(x);
    solveR(x);
    if (value[x] >= INF) {
        cout<<-1<<"\n";
    } else {
        cout<<value[x]<<"\n";
    }
    return 0;
}
