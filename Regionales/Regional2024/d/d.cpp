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

struct Hopcroft{ // Matching maximo en bipartito en O(sqrt(n)*m)
	int n, m;
	vector<vector<int>> g;    // [0,n) -> [0,m)
	vector<int> mt, inv, ds;  // mt :  [0..n)->[0..m) contiene el matching n-m
	                          // inv : [0..m)->[0..n) contiene el matching m-n
	void init(int n_, int m_) { n = n_, m = m_, g.resize(n_); }
	void add_edge(int u, int v) { g[u].pb(v); }
	bool bfs(){
		ds.assign(n, -1); queue<int> q;
		forn(i, n) if(mt[i] < 0) ds[i] = 0, q.push(i);
		bool r = false;
		while(not q.empty()){
			int x = q.front(); q.pop();
			for(auto y : g[x]){
				if(inv[y] >= 0 and ds[inv[y]] < 0)
					ds[inv[y]] = ds[x]+1, q.push(inv[y]);
				else if(inv[y] < 0) r = true;
			}
		}
		return r;
	}
	bool dfs(int x){
		for(auto y : g[x])
		if(inv[y] < 0 or(ds[inv[y]] == ds[x]+1 and dfs(inv[y]))){
			inv[y] = x; mt[x] = y;
			return true;
		}
		ds[x] = 1<<30;
		return false;
	}
	int mm(){
		int r = 0;
		mt.assign(n, -1), inv.assign(m, -1);
		while(bfs()) forn(i, n) if(mt[i]<0) r += dfs(i);
		return r;
	}
};

int N;
vector<vector<int>> G;

void contar(vector<int>& nodos) {
	forn(i,N) {
		bool unir = true;
		for (int nodo : nodos) {
			if (G[i][nodo] != 1) {
				unir = false;
				break;
			}
		}
		if (unir) {
			for (int nodo : nodos) G[i][nodo] = G[nodo][i] = 0;
			nodos.push_back(i);
		}
	}
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>N;
	G.assign(N, vector<int>(N));
	forn(i,N) forn(j,N) {
		char c; cin>>c;
		G[i][j] = c-'0';
	}

	Hopcroft h;
	h.init(100000,100000);
	
	// Busco los cliques y pongo el nodo comun como front
	int nextN = 0, nextM = 0;
	forn(i,N) forn(j,N) {
		if (G[i][j] == 1) {
			G[i][j] = G[j][i] = 0;
			vector<int> nodos = {i,j};
			contar(nodos);
			int count = nodos.size();
			while (count--) {
				h.add_edge(nextN, nextM++);
			}
			nextN++;
		}
	}

	cout<<h.mm()<<"\n";

    return 0;
}

// https://codeforces.com/gym/105505/problem/D
