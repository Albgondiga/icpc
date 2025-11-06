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
	struct edge {int to, rev; ll f, cap; int id;};
	vector<vector<edge>> g; vector<ll> dd;
	Dinic(int n_): n(n_), dist(n_+2), q(n_+2), work(n_+2), g(n_+2), dd(n_+2)
	               {} // Deja espacio para el min_cap
	void add_edge(int s, int t, ll cap, ll mincap = 0, int id = -1){
		// assert(0 <= mincap and mincap <= cap);
		mincap = max(mincap, 0LL);
		if(mincap>cap){puts("-1");exit(0);}
		dd[s] += mincap; dd[t] -= mincap;
		g[s].pb({t, sz(g[t]),   0, cap-mincap, id});
		g[t].pb({s, sz(g[s])-1, 0, 0, -1}); // Residual: cap = 0 y flujo < 0
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
	}
	ll max_flow_min_cap(int s, int t){
		add_edge(t, s, INF);
		ll w = 0;
		forn(i, n+1){
			if     (dd[i] > 0) add_edge(i, n+1,  dd[i]), w += dd[i];
			else if(dd[i] < 0) add_edge(n, i,   -dd[i]);
		}
		ll f = max_flow(n, n+1);
		if(f != w) return -1;
		forn(i, n) if(dd[i] != 0) g[i].pp();
		ll ff = max_flow(s, t); g[s].pp(), g[t].pp();
		return ff;
	}
};

const int N = 26;
// Minimo y maximo flujo para cada letra
ll mini[N], maxi[N];
// Sets de casillas para cada letra
set<int> amarillas[N], verdes[N], negras[N];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int g, l; cin>>g>>l;
    
    // El maximo inicial es toda la palabra
    forn(i,N) maxi[i] = l;

    vector<bool> reservada(l,false);
    forn(i,g-1) {
        string s, t; cin>>s>>t;
        vector<ll> count(N,0);
        forn(j,l) {
            int letra = s[j]-'a';
            char color = t[j];
            // Si es negro lo marco para despues actualizar el maximo
            if (color == 'B') negras[letra].insert(j);
            else if (color == 'G') {
                count[letra]++;
                reservada[j] = true;
                verdes[letra].insert(j);
            } else {
                count[letra]++;
                amarillas[letra].insert(j);
            }
        }
        forn(j,N) mini[j] = max(mini[j], count[j]);
    }

    forn(i,N) {
        //mini[i] = amarillas[i].size() + verdes[i].size();
        if (!negras[i].empty()) maxi[i] = mini[i];
    }

    // Dos nodos fuente, un nodo por letra, un nodo por pos, nodo sumidero
    /*
    0 a N-1: letras
    N a N+l-1: pos
    N+l: s
    N+l+1: t
    */
    int s = N+l;       
    int t = N+l+1; 
    Dinic d(N+l+2);

    forn(i,N) d.add_edge(s, i, maxi[i], mini[i]);

    // letras → posiciones
    forn(i,N) forn(j,l) {
        if (verdes[i].count(j)) {
            // posición fija para esa letra
            d.add_edge(i, N+j, 1);
        } else if (!amarillas[i].count(j) and !negras[i].count(j) and !reservada[j]) {
            // posición libre posible
            d.add_edge(i, N+j, 1);
        }
    }

    // posiciones → sumidero
    forn(j,l)
        d.add_edge(N+j, t, 1);

    ll flow = d.max_flow_min_cap(s, t);
    string ans(l, '_');
    forn(i,N) {
        for (auto &e : d.g[i]) {
            if (e.to >= N && e.to < N+l && e.f > 0) {
                int pos = e.to - N;
                ans[pos] = 'a' + i;
            }
        }
    }
    cout<<ans<<"\n";

    return 0;
}

// https://codeforces.com/gym/104875
