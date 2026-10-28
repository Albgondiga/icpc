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

// https://usaco.guide/gold/all-roots?lang=cpp

const int N = 2e5+1;
vector<int> adj[N];

int f[N], h[N], g[N];

// Encontrar f, h, best para cada nodo
void dfs1(int u, int p) {
    f[u] = h[u] = 0;

    for (int c : adj[u]) {
        if (c == p) continue;
        dfs1(c, u);

        int dist = f[c] + 1;
        if (dist > f[u]) { 
            h[u] = f[u]; 
            f[u] = dist; 
        }
        else if (dist > h[u]) h[u] = dist;
    }
}

void dfs2(int u, int p) {     // de arriba hacia abajo
    for (int c : adj[u]) {
        if (c == p) continue;
        int otro = ((f[c] + 1 == f[u]) ? h[u] : f[u]);
        g[c] = max(g[u], otro) + 1;
        dfs2(c, u);
    }
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

	int n; cin>>n;
	forn(i,n-1) {
		int u, v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs1(1,0);
	dfs2(1,0);
	for (int i = 1; i <= n; i++) cout<<max(f[i], g[i])<<" ";

    return 0;
}
