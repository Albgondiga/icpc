#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define fst first
#define snd second
#define fore(e,c) for(const auto &e : (c))
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

#define blanco 0
#define negro 1

const int N = 1e5+1;
const ll MOD = 1e9+7;

int n;
vector<int> adj[N];
// dp[v][k] tiene de cuantas maneras puedo pintar el subarbol de v
// con v de color k
vector<vector<ll>> dp;

ll f(int v, int color, int p = 0) {
    if (dp[v][color] == -1) {
        ll count = 1;
        if (color == blanco) {
            for (int u : adj[v]) {
                if (u == p) continue;
                count *= (f(u,blanco,v) + f(u,negro,v));
                count %= MOD;
            }
        } else {
            for (int u : adj[v]) {
                if (u == p) continue;
                count *= f(u,blanco,v);
                count %= MOD;
            }
        }
        dp[v][color] = count;
    }
    return dp[v][color];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    forn(i,n-1) {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dp.assign(n+1, vector<ll>(2, -1));

    f(1, blanco);
    f(1, negro);

    cout<<((dp[1][blanco]+dp[1][negro])%MOD)<<"\n";

    return 0;
}
