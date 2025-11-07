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

const ll INF = 1e18;

struct Dinic{ // O(n^2 * m)
	int n, src, dst;
	vector<int> dist, q, work; // dist: distancias desde S, sin ponderar
	struct edge {int to, rev; ll f, cap;};
	vector<vector<edge>> g; vector<ll> dd;
	Dinic(int n_): n(n_), dist(n_+2), q(n_+2), work(n_+2), g(n_+2), dd(n_+2)
	               {} // Deja espacio para el min_cap
	void add_edge(int s, int t, ll cap, ll mincap = 0){
		// assert(0 <= mincap and mincap <= cap);
		dd[s] += mincap; dd[t] -= mincap;
		g[s].pb({t, sz(g[t]),   0, cap-mincap});
		g[t].pb({s, sz(g[s])-1, 0, 0}); // Residual: cap = 0 y flujo < 0
	}
	bool dinic_bfs(){
		fill(all(dist), -1); dist[src] = 0;
		int qt = 0; q[qt++] = src;
		for(int qh = 0; qh < qt; qh ++){
			int u = q[qh];
			fore(e, g[u]){
				int v = e.to;
				if(dist[v] < 0 and e.f < e.cap) dist[v] = dist[u]+1, q[qt++] = v;
			}
		}
		return dist[dst] >= 0;
	}	
	ll dinic_dfs(int u, ll f){
		if(u == dst) return f;
		for(int &i = work[u]; i < sz(g[u]); i ++){
			edge &e = g[u][i];
			if(e.cap <= e.f) continue;
			int v = e.to;
			if(dist[v] == dist[u]+1){
				ll df = dinic_dfs(v, min(f, e.cap - e.f));
				if(df > 0){
					e.f += df; g[v][e.rev].f -= df;
					return df;
				}
			}
		}
		return 0;
	}
	ll max_flow(int _src, int _dst){
		src = _src; dst = _dst;
		ll result = 0;
		while(dinic_bfs()){
			fill(all(work), 0);
			while(ll delta = dinic_dfs(src, INF)) result += delta;
		}
		return result;
	} // ll max_flow_min_cap() esta en el mcMF

};

vector<vector<int>> get_edge_disjoint_paths(Dinic &F, int s, int t) {
    vector<vector<int>> paths;
    // Hacemos una copia de los flujos, para poder "consumirlos"
    vector<vector<int>> used(sz(F.g));
    for (int i = 0; i < sz(F.g); i++) used[i].assign(sz(F.g[i]), 0);

    while (true) {
        vector<int> path, parent(sz(F.g), -1), pe(sz(F.g), -1);
        queue<int> q;
        q.push(s);
        parent[s] = s;

        // DFS/BFS sobre aristas con flujo positivo (f > 0)
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t) break;
            for (int i = 0; i < sz(F.g[u]); i++) {
                auto &e = F.g[u][i];
                if (e.f > 0 && !used[u][i] && parent[e.to] == -1) {
                    parent[e.to] = u;
                    pe[e.to] = i;
                    q.push(e.to);
                }
            }
        }

        if (parent[t] == -1) break; // no queda camino

        // reconstruir camino y marcar aristas como usadas
        int x = t;
        while (x != s) {
            int u = parent[x], i = pe[x];
            used[u][i] = 1;
            x = u;
        }

        // reconstrucción del camino
        vector<int> path_rev;
        x = t;
        while (x != s) {
            path_rev.pb(x);
            x = parent[x];
        }
        path_rev.pb(s);
        reverse(all(path_rev));
        paths.pb(path_rev);
    }

    return paths;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m; cin>>n>>m;

    Dinic d(2*n+1);
    int s = 1, t = 2*n;

    forn(i,m) {
        int u, v; cin>>u>>v;
        d.add_edge(u,n+v,1);
    }

    ll f = d.max_flow(s,t);
    
    vector<vector<int>> paths = get_edge_disjoint_paths(d,s,t);

    cout<<paths.size()<<"\n";
    for (auto path : paths) {
        cout<<path.size()<<"\n";
        for (int x : path) cout<<x<<" ";
        cout<<"\n";
    }

    return 0;
}
