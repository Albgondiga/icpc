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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

int n, LOG;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout, depth;
vector<vector<int>> up;

void dfs(int v, int p, int d = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    depth[v] = d;
    for (int i = 1; i <= LOG; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, d+1);
        }
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int go_up(int u, int v) {
    for (int i = LOG; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return u;
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    u = go_up(u,v);
    return up[u][0];
}


int getKthAncestor(int node, int k) {
    if(depth[node] < k) {
        return -1;
    }
    for(int j = LOG - 1; j >= 0; j--) {
        if(k >= (1 << j)) {
            node = up[node][j];
            k -= 1 << j;
        }
    }
    return node;
}

void preprocess(int root) {
    depth.resize(n+1);
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    LOG = ceil(log2(n+1));
    up.assign(n+1, vector<int>(LOG + 1));
    dfs(root, root);
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int q;
	cin>>n>>q;
    adj.assign(n+1, vector<int>());
    forn(i, n-1) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    preprocess(1);
    while(q--) {
        int a, b; cin>>a>>b;
        cout<<depth[a]+depth[b]-2*depth[lca(a,b)]<<"\n";
    }

    return 0;
}