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

const int MAXN = 2e4+5;

int n, m, s;

// ===== UF =====
int link[MAXN], r[MAXN];

int find(int a) {
  return link[a] = (link[a] == a ? a : find(link[a]));
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    if (same(a,b)) return;
    a = find(a), b = find(b);
    if (r[a] == r[b]) r[a]++;
    if (r[a] < r[b]) swap(a,b);
    link[b] = a;
}

// ====== Binary Lifting =====
int l, timer;
vector<pair<int,int>> adj[MAXN];
vector<vector<int>> up, mini;
vector<int> tin, tout;

void dfs(int v, int p, int w) {
    tin[v] = ++timer;
    up[v][0] = p;
    mini[v][0] = w;
    for (int i = 1; i <= l; i++) {
        // Subir 2^i es igual que subir 2^(i-1)+2^(i-1)
        up[v][i] = up[up[v][i-1]][i-1];
        mini[v][i] = min(mini[v][i-1], mini[up[v][i-1]][i-1]);
    }
    for (auto u : adj[v]) {
        if (u.first != p) dfs(u.first,v,u.second);
    }
    tout[v] = ++timer;
}

// u de v
bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

// Retorna la arista mas pequeña desde u a lca(u,v)
int lca(int u, int v) {
    bool subir = true;
    if (is_ancestor(u,v)) subir = false;
    int arista = 1e9;
    for (int i = l; i >= 0; i--) {
        if (!is_ancestor(up[u][i],v)) {
            arista = min(arista, mini[u][i]);
            u = up[u][i];
        }
    }
    if (subir) arista = min(arista, mini[u][0]);
    return arista;
}

void preprocess(int root) {
    tin.assign(n+1,0), tout.assign(n+1,0);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n+1, vector<int>(l+1,0));
    mini.assign(n+1, vector<int>(l+1,0));
    dfs(root, root, 1e9);
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while (cin>>n) {
        cin>>m>>s;

        vector<tuple<int,int,int>> edges;
        forn(i,m) {
            int u, v; int w;
            cin>>u>>v>>w;
            edges.push_back({w,u,v});
        }
        sort(edges.begin(), edges.end(), greater<tuple<int,int,int>>());
    
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            link[i] = i;
            r[i] = 0;
        }  
    
        for (const tuple<int,int,int>& e : edges) {
            auto [w, u, v] = e;
            if (!same(u,v)) {
                unite(u,v);
                adj[u].push_back({v,w});
                adj[v].push_back({u,w});
            }
        }
    
        preprocess(1);

        while (s--) {
            int u, v; cin>>u>>v;
            cout<<min(lca(u,v),lca(v,u))<<"\n";
        }
    }

    return 0;
}
