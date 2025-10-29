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

// Arriba, abajo, izquierda, derecha
const vector<int> dI = {-1,1,0,0}, dJ = {0,0,-1,1};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, m, c;
    cin>>m>>n>>c;
    vector<vector<char>> G(n, vector<char>(m));
    ii B;
    // Leo el grafo
    forn(i,n) forn(j,m) {
        cin>>G[i][j];
        if (G[i][j] == 'B') B = {i,j};
    }

    vector<ll> cost(c);
    forn(i,c) cin>>cost[i];

    // Dos nodos por cada casilla y uno extra para representar afuera
    Dinic d(2*n*m+1); 
    // Los nodos de 0 a n*m-1 son los nodos de entrada, los nodos de n*m a 2*n*m-1 son los de salida, 2*n*m es el ultimo
    forn(i,n) forn(j,m) {
        // Agrego la arista intermedia
        ll cap = ((G[i][j] == '.' or G[i][j] == 'B') ? INF : cost[G[i][j]-'a']);
        d.add_edge(i*m + j, n*m + i*m + j, cap); 
        // Agrego las aristas con los adyacentes (nodo de salida a nodo de entrada)
        forn(k,4) {
            int i2 = i+dI[k], j2 = j+dJ[k];
            if (valid(i2, j2, n, m)) d.add_edge(n*m + i*m + j, i2*m + j2, INF);
        }
        // Agrego las aristas hacia afuera (si es necesario)
        if (i == 0 or i == n-1 or j == 0 or j == m-1) {
            d.add_edge(n*m + i*m + j, 2*n*m, INF);
        }
    }

    ll min_cut = d.max_flow(B.first*m + B.second, 2*n*m);
    if (min_cut >= INF) min_cut = -1;

    cout<<min_cut<<"\n";

    return 0;
}
