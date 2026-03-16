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

int nodos, aristas;
vector<vector<int>> adj;
vector<bool> vis;

void dfs(int v) {
    if (vis[v]) return;
    nodos++;
    for (int u : adj[v]) {
        dfs(v);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        int n, m; cin>>n>>m;
        adj.assign(n+1, vector<int>());
        forn(i,m) {
            int u, v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vis.assign(n+1, false);
        for (int i = 1; i <= n; i++) {
            if (not vis[i]) dfs(i);

        }
    }

    return 0;
}
