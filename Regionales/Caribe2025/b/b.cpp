#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define fore(e,c) for(const auto &e : (c))

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

bool valid(int i, int j, int n, int m) {
    return (i >= 0 and i < n and j >= 0 and j < m);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
	int n; cin>>n;
	vector<vector<int>> tipo(n, vector<int>(n)), costo(n, vector<int>(n));

    vector<int> candidatos;

	forn(i,n) forn(j,n) {
		cin>>tipo[i][j];
        if ((tipo[i][j] == 2 or tipo[i][j] == 4) and !(i == 0 and j == 0)) candidatos.push_back(i*n+j);
	}
	forn(i,n) forn(j,n) {
		cin>>costo[i][j];
		if (costo[i][j] == -1) costo[i][j] = INF;
	}

    // Dos nodos por cada casilla y uno extra para representar afuera
    Dinic d(2*n*n+1); 
    // Los nodos de 0 a n*n-1 son los nodos de entrada, los nodos de n*n a 2*n*n-1 son los de salida, 2*n*n es el ultimo
    forn(i,n) forn(j,n) {
        // Agrego la arista intermedia
        ll cap = costo[i][j];
        if (cap == -1) {
            if (tipo[i][j] == 0) cap = 0;
            else cap = INF;
        }
        d.add_edge(i*n + j, n*n + i*n + j, cap); 
        // Agrego las aristas con los adyacentes (nodo de salida a nodo de entrada)
        if (valid(i+1, j, n, n)) d.add_edge(n*n + i*n + j, (i+1)*n + j, INF);
        if (valid(i, j+1, n, n)) d.add_edge(n*n + i*n + j, i*n + (j+1), INF);
    }

    // Busco el mejor candidato a romper y lo guardo
    int mejor = -1;
    ll mini = INF;
    for (int candidato : candidatos) {
        ll min_cut = d.max_flow(0, candidato);
        if (min_cut < mini) {
            mini = min_cut;
            mejor = candidato;
        }
    }

    //
    ll min_cut = d.max_flow(0, candidato);


    return 0;
}
