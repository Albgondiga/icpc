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

// https://codeforces.com/gym/106679/problem/E

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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m1, m2; cin>>n>>m1>>m2;
    set<ii> s_edges1, s_edges2;
    forn(i,m1) {
        int u, v; cin>>u>>v;
        if (u > v) swap(u, v);
        s_edges1.insert({u,v});
    }
    forn(i,m2) {
        int u, v; cin>>u>>v;
        if (u > v) swap(u, v);
        s_edges2.insert({u,v});
    }

    if (m1 != m2) {
        cout<<-1<<"\n";
        return 0;
    }

    vector<ii> comunes;
    for (const ii& e : s_edges1) {
        if (s_edges2.count(e)) comunes.push_back(e);
    }
    for (const ii& e : comunes) {
        s_edges1.erase(e);
        s_edges2.erase(e);
    }

    vector<ii> edges1, edges2;
    for (const ii& e : s_edges1) edges1.push_back(e);
    for (const ii& e : s_edges2) edges2.push_back(e);

    /*
     * edges1.size() + edges2.size() + 2 nodos
     * {1,...,edges1.size()-1}, {edges1.size(),...,edges1.size() + edges2.size() - 1}
     * s = edges1.size() + edges2.size(), t = edges1.size() + edges2.size() + 1
     */
    Dinic dinic(edges1.size() + edges2.size() + 2);
    int s = edges1.size() + edges2.size(), t = edges1.size() + edges2.size() + 1;

    forn(i, edges1.size()) dinic.add_edge(s, i, 1);
    forn(i, edges2.size()) dinic.add_edge(edges1.size() + i, t, 1);

    forn(i, edges1.size()) {
        ii e1 = edges1[i];
        forn(j, edges2.size()) {
            ii e2 = edges2[j];
            if (e1.first == e2.first or e1.first == e2.second or e1.second == e2.first or e1.second == e2.second) {
                dinic.add_edge(i, edges1.size() + j, 1);
            }
        }
    }

    ll k = dinic.max_flow(s, t);
    cout<<k+2*(edges2.size()-k)<<"\n";

    return 0;
}
