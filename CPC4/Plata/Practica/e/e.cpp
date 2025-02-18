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

const int N = 1e5+1;
vector<int> adj[N];
int n, m, q, p[N], lvl[N];

const int LN = 21;
int a[N], up[N][LN+1];

void dfs(int x, int p = 0) {
    up[x][0] = p;
    lvl[x] = lvl[p] + 1;

    for (int i = 1; i <= LN; i++)
        up[x][i] = up[up[x][i-1]][i-1];
    for (int to : adj[x])
        if (to != p)
            dfs(to, x);
}

int lca(int u, int v) {
    if (lvl[u] > lvl[v])
        swap(u, v);
    for (int i = LN; i >= 0; i--)
        if (lvl[v] - (1 << i) >= lvl[u])
            v = up[v][i];
    if (u == v)
        return u;
    for (int i = LN - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

void solve() {
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>m;
        adj[i].resize(m);
        for(int j = 0; j < m; j++)
            cin>>adj[i][j];
    }
    dfs(1);
    cin>>q;
    while(q--) {
        int v, w; cin>>v>>w;
        cout<<lca(v,w)<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;
    for (int i = 1; i <= t; i++) {
        cout<<"Case "<<i<<":\n";
        solve();
    }

    return 0;
}