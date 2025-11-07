
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

    vector<pair<int,int>> min_cut_edges(int s) {
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &e : g[u]) {
                if (!vis[e.to] && e.cap - e.f > 0) {
                    vis[e.to] = 1;
                    q.push(e.to);
                }
            }
        }

        vector<pair<int,int>> cut;
        forn(u, n) if (vis[u]) {
            for (auto &e : g[u]) {
                if (!vis[e.to] && e.cap > 0) { // borde saturado
                    cut.pb({u, e.to});
                }
            }
        }
        return cut;
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m, k; cin>>n>>m>>k;

    Dinic d(n+m+3);
    int s = n+m+1, t = n+m+2;

    forn(i,k) {
        int u, v; cin>>u>>v;
        d.add_edge(u,n+v,1);
    }

    for(int i = 1; i <= n; i++) {
        d.add_edge(s,i,1);
    }
    for(int i = 1; i <= m; i++) {
        d.add_edge(n+i,t,1);
    }

    ll f = d.max_flow(s,t);
    
    cout<<f<<"\n";
    vector<pair<int,int>> match;
    for (int u = 1; u <= n; u++) {
        for (auto &e : d.g[u]) {
            if (e.to > n && e.to <= n+m && e.f == e.cap && e.cap > 0) {
                match.pb({u, e.to-n}); // índices locales en U,V
            }
        }
    }

    for (auto [u,v] : match) cout<<u<<" "<<v<<"\n";

    return 0;
}
