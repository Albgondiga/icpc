#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define all(v) begin(v), end(v)
#define fore(e,c) for(const auto &e : (c))
#define pb push_back
#define pf push_front
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef pair<ll,ll> pll;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

const ll INF = 1e18;
const int N = 1e3+5;

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

    // Primero m aristas, luego n nodos
    Dinic d(2*N+2);

    int n, m; cin>>n>>m;
    int s = m+n, t = m+n+1;

    vector<ll> costo(n);
	// Por cada nodo pierdo
    for (int i = 0; i < n; i++) {
		cin>>costo[i];
		d.add_edge(i+m, t, costo[i]);
	};

    ll ans = 0;
    map<pair<int,int>, int> mapa;
    int siguiente = 0;

    for (int i = 0; i < m; i++) {
        int a, b; ll w; cin>>a>>b>>w;
        if (a > b) swap(a,b);
        if (mapa.find({a,b}) == mapa.end()) {
			mapa[{a,b}] = siguiente++;
			// Por cada arista gano
			d.add_edge(s, mapa[{a,b}], w);
		}
		// Obtengo el nodo de la arista
        int e = mapa[{a,b}];
        // Ajusto nodos a grafo bipartito
        a--; b--; a += m; b += m;
        // Aristas del medio
        d.add_edge(e, a, INF);
        d.add_edge(e, b, INF);
        
        ans += w;
    }

    cout<<max(0LL, ans-d.max_flow(s, t))<<"\n";

    return 0;
}
