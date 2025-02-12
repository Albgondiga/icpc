#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

const ll MAX = 1e5+1;
vector <pair<ll,ll>> ady[MAX];
ll n, lvl[MAX];

const ll LN = 21;
ll up[MAX][LN+1], dist[MAX][LN+1];

void dfs(ll x, ll p = 0, ll d = 0) {
    up[x][0] = p, lvl[x] = lvl[p] + 1;
    dist[x][0] = d; 
    for(ll i = 1; i <= LN; i++) {
        up[x][i] = up[up[x][i-1]][i-1];
        dist[x][i] = dist[x][i-1] + dist[up[x][i-1]][i-1];
    }
    for(auto to : ady[x])
        if(to.first != p)
            dfs(to.first, x, to.second);
}

int lca(int u, int v) {
    if(lvl[u] > lvl[v])
        swap(u, v);
    for(int i = LN; i >= 0; i--)
        if(lvl[v] - (1 << i) >= lvl[u])
            v = up[v][i];
    if(u == v)
        return u;
    for(int i = LN - 1; i >= 0; i--) {
        if(up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

ll dist_query(ll u, ll v) {
    if(lvl[u] > lvl[v])
        swap(u, v);

    ll ans = 0;
    for(ll i = LN; i >= 0; i--)
        if(lvl[v] - (1 << i) >= lvl[u]) {
            ans += dist[v][i];
            v = up[v][i];
        }
    
    if(u == v)
        return ans;
    
    for(ll i = LN - 1; i >= 0; i--) {
        if(up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
            ans += dist[u][i] + dist[v][i];
        }
    }
    return ans;
}

ll kth_query(ll u, ll v, ll k) {
    k--;
    ll _lca = lca(u, v);
    if (lvl[u] - lvl[_lca] <= k) {
        for(int j = LN - 1; j >= 0; j--) {
            if(k >= (1 << j)) {
                u = up[u][j];
                k -= 1 << j;
            }
        }
        return u;
    } else {
        k -= lvl[u] - lvl[_lca];
        k = lvl[v] - lvl[_lca] - k;
        for (int i = 0; i < LN; i++) {
            if (k & (1 << i)) {
                v = up[v][i];
            }
        }
        return v;
    }
}

void solve() {
    cin>>n;
    for (ll i = 1; i <= n-1; i++) {
        ll a, b, c; cin>>a>>b>>c;
        ady[a].push_back({b, c});
        ady[b].push_back({a, c});
    }
    dfs(1);
    string s;
    while (cin>>s) {
        if (s == "DONE") break;
        ll a, b, k; cin>>a>>b;
        if (s == "DIST") {
            cout<<dist_query(a, b)<<'\n';
        } else {
            cout<<kth_query(a, b, k)<<'\n';
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; cin>>t;
    while (t--) solve();

    return 0;
}
