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

const int N = 1e5+5;
vector<int> adj[N];
int vis[N], low[N];
ll subtree[N];
vector<pair<int,int>> puentes;
int t = 0;
ll n, m;

int dfs(int x, int r = 0) {
    vis[x] = low[x] = ++t;
    subtree[x] = 1LL;
    for (int y : adj[x]) {
        if (y == r) continue;
        if (!vis[y]) {
            subtree[x] += dfs(y, x);
            low[x] = min(low[x], low[y]);
            if (low[y] > vis[x]) {
                puentes.push_back({x,y});
            }
        } else {
            low[x] = min(low[x], vis[y]);
        }
    }
    return subtree[x];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        cin>>n>>m;

        t = 0;
        puentes.clear();
        for (int i = 1; i <= n; i++) {
            vis[i] = low[i] = subtree[i] = 0LL;
            adj[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int u, v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1);

        ll ans = n*(n-1)/2, maxi = 0;
        for (auto e : puentes) {
            int u = e.first, v = e.second;
            maxi = max(maxi, (n-subtree[v])*subtree[v]);
        }
        cout<<ans-maxi<<"\n";
    }

    return 0;
}
