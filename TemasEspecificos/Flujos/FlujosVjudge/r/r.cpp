#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

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
const int N = 1e5+5;

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

#define S 0
#define M 1
#define L 2
#define XL 3
#define XXL 4
#define XXXL 5

int idx(string& s) {
    if (s == "S") return S;
    if (s == "M") return M;
    if (s == "L") return L;
    if (s == "XL") return XL;
    if (s == "XXL") return XXL;
    if (s == "XXXL") return XXXL;
    return -1;
}

string talla(int s) {
    if (s == S) return "S";
    if (s == M) return "M";
    if (s == L) return "L";
    if (s == XL) return "XL";
    if (s == XXL) return "XXL";
    if (s == XXXL) return "XXXL";
	return "ERROR";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<ll> shirts(6);
    for (int i = 0; i < 6; i++) {
        cin>>shirts[i];
    }

    int n; cin>>n;
    Dinic d(n+6+2);
    int s = n+6, t = n+6+1;

    // Arista de s a talla
    for (int i = 0; i < 6; i++) {
        d.add_edge(s, i, shirts[i]);
    }

    for (int i = 0; i < n; i++) {
        // Arista de persona a t
        d.add_edge(i+6, t, 1);

        // Leer tallas
        string s; cin>>s;
        string talla1 = "", talla2 = "";
        for (char c : s) {
            if (c == ',') {
                swap(talla1, talla2);
                continue;
            }
            talla1 += c;
        }
        // Arista de persona a talla
        int t1 = idx(talla1), t2 = idx(talla2);
        if (t1 != -1) d.add_edge(t1, i+6, INF);
        if (t2 != -1) d.add_edge(t2, i+6, INF);
    }

    if (d.max_flow(s, t) == n) {
		cout<<"YES\n";
		vector<string> ans(n);
		for (int shirt = 0; shirt < 6; shirt++) {
			for (int i = 0; i < (d.g[shirt]).size(); i++) {
				if (((d.g[shirt])[i]).f > 0) ans[((d.g[shirt])[i]).to - 6] = talla(shirt);
			}
		}
		for (string& x : ans) cout<<x<<"\n";
	} else cout<<"NO\n";

    return 0;
}
