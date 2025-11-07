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

#define all(v) begin(v), end(v)
#define fore(e,c) for(const auto &e : (c))

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

    // n floors, cada uno con k rooms. m stairs en total.
    int n, k, m; cin>>n>>k>>m;

    /*
    [0,n*k) in
    [n*k,2*n*k) out
    */
    Dinic d(2*n*k+2);
    int s = 2*n*k, t = 2*n*k+1;

    // Leer caps
    forn(i,n) {
        forn(j,k) {
            ll c; cin>>c;
            // Arista intermedia
            d.add_edge(i*k+j, n*k + i*k+j, c);
        }
    }

    forn(j,k) {
        // Arista de s a rooms de piso 1
        d.add_edge(s, j, INF);
        // Arista de rooms de piso n-1 a t
        d.add_edge(n*k + (n-1)*k+j, t, INF);
    }

    // Aristas entre pisos
    forn(i,m) {
        int f, u, v; cin>>f>>u>>v;
        f--; u--; v--;
        d.add_edge(n*k + f*k+u, (f+1)*k+v, INF);
    } 

    // Hago n flujos para los turnos de n a 1
    vector<ll> ans(n);
    ll flow = 0LL;
    for (int i = n-1; i >= 0; i--) {
        ll nuevo = d.max_flow(s,t);
        flow += nuevo;
        ans[i] = flow;
        if (i > 0) forn(j,k) d.add_edge(n*k + (i-1)*k+j, t, INF);
    }

    for (ll x : ans) cout<<x<<" ";
    cout<<"\n";

    return 0;
}
