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

const int N = 1e4+5;
int vis[N], low[N];
vector<int> adj[N];
int t;
set<int> aps;

void dfs(int x, int r = 0) {
    int hijos = 0;
    vis[x] = low[x] = ++t;
    for (int y : adj[x]) {
        if (y == r) continue;
        if (!vis[y]) {
            hijos++;
            dfs(y, x);
            low[x] = min(low[x], low[y]);
            if (vis[x] <= low[y] and r != 0) {
                aps.insert(x);
            }
        } else {
            low[x] = min(low[x], vis[y]);
        }
    }
    if (r == 0 and hijos > 1) {
        aps.insert(x);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while (true) {
        int n, m; cin>>n>>m;
        
        if (n == 0 and m == 0) return 0;

        // Limpiar
        for (int i = 1; i <= n; i++) {
            vis[i] = low[i] = 0;
            adj[i].clear();
        }
        aps.clear();
        t = 0;

        for (int i = 1; i <= m; i++) {
            int u, v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1);

        cout<<aps.size()<<"\n";
    }

    return 0;
}
