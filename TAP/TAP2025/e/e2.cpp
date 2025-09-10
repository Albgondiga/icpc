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

const int N = 2e5+1, L = 20;
vector<int> adj[N];
int up[N][L+1];
int depth[N], tin[N], tout[N];
ll maes[N];
int timer = 0;

pair<ll,int> ans; 

bool is_ancestor(int u, int v) {
    return (tin[u] <= tin[v] and tout[u] >= tout[v]);
}

void dfs_lca(int v, int p = 1, int d = 0) {
    tin[v] = ++timer;
    up[v][0] = p;

    depth[v] = d;

    for (int i = 1; i <= L; i++)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v])
        if (u != p) dfs_lca(u, v, d+1);

    tout[v] = ++timer;
}

int lca(int u, int v) {
    if (is_ancestor(u,v)) return u;
    if (is_ancestor(v,u)) return v;
    for (int i = L; i >= 0; i--) {
        if (not is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void dfs(vector<pair<int,int>>& niveles, vector<ll>& count, int v, int p = 1, int nivel = 1) {
    if (niveles[nivel].first == -1) niveles[nivel] = {0, 0};
    if (maes[v]) {
        if (niveles[nivel].first == 0) niveles[nivel].first = v;
        niveles[nivel].second = v;
        count[nivel] += maes[v];
    }
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(niveles, count, u, v, nivel+1);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    for (int i = 2; i <= n; i++) {
        cin>>maes[i];
        if (maes[i] > ans.first) ans = {maes[i], 1};
    }

    for (int i = 0; i < n-1; i++) {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_lca(1);

    for(int u : adj[1]) {
        vector<pair<int,int>> niveles(n, {-1,-1});
        vector<ll> count(n);
        dfs(niveles, count, u);
        for (int nivel = 2; nivel < n; nivel++) {
            if (u == 0) continue;
            if (u == -1) break;
            auto x = niveles[nivel];
            int u = x.first, v = x.second;
            int a = lca(u, v);
            int turno = (depth[u]-depth[a]+1);
            if (count[nivel] == ans.first) {
                ans = {count[nivel], min(turno, ans.second)};
            } else if (count[nivel] > ans.first) {
                ans = {count[nivel], turno};
            }
        }
    }

    cout<<ans.first<<" "<<ans.second<<"\n";

    return 0;
}
