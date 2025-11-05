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

typedef ll tf;          typedef ll tc;
const tf INFFLOW = 1e9; const tc INFCOST = 1e9;
struct MCF { // O(n^2 * m^2), no se banca ciclos de costo negativo
	int n;
	vector<tc> prio, pot; vector<tf> curflow; vector<int> prevedge, prevnode;
	priority_queue<pair<tc, int>, vector<pair<tc, int>>,
	               greater<pair<tc, int>>> q;
	struct edge{int to, rev; tf f, cap; tc cost;};
	vector<vector<edge>> g; vector<tf> dd; tc dc = 0;
	MCF(int n_) : n(n_), prio(n_+2), pot(n_+2), curflow(n_+2),
	              prevedge(n_+2), prevnode(n_+2), g(n_+2), dd(n_+2) {}
	void add_edge(int s, int t, tc cost, tf cap, tf mincap = 0){
		// assert(0 <= mincap and mincap <= cap);
		dd[s] += mincap; dd[t] -= mincap; dc += mincap*cost;
		g[s].pb((edge){t, sz(g[t]),   0, cap-mincap, cost});
		g[t].pb((edge){s, sz(g[s])-1, 0, 0,         -cost});
	}
	pair<tf, tc> get_flow(int s, int t){
		tf flow = 0; tc cost = 0;
		while(1){
			q.push({0, s});
			fill(all(prio), INFCOST); 
			prio[s] = 0; curflow[s] = INFFLOW;
			while(not q.empty()){
				auto [d, u] = q.top();
				q.pop();
				if(d != prio[u]) continue;
				forn(i, sz(g[u])){
					auto& [v, _, f, cap, c] = g[u][i];
					if(cap <= f) continue;
					tc nprio = prio[u] + c + pot[u] - pot[v];
					if(prio[v] > nprio){
						prio[v] = nprio;
						q.push({nprio, v});
						prevnode[v] = u; prevedge[v] = i;
						curflow[v] = min(curflow[u], cap-f);
					}
				}
			}
			if(prio[t] == INFCOST) break;
			forn(i, n) pot[i] += prio[i];
			tf df = min(curflow[t], INFFLOW-flow);
			flow += df;
			for(int v = t; v != s; v = prevnode[v]){
				auto& [_, rev, f, cap, c] = g[prevnode[v]][prevedge[v]];
				f += df; g[v][rev].f -= df;
				cost += df*c;
			}
		}
		return {flow, cost};
	}
	pair<tf, tc> get_flow_min_cap(int s, int t){
		// cost(aristas en ciclo) = f*c, como todas
		add_edge(t, s, 0, INFFLOW); ll w = 0;
		forn(i, n){
			if     (dd[i] > 0) add_edge(i, n+1, 0,  dd[i]), w += dd[i];
			else if(dd[i] < 0) add_edge(n, i,   0, -dd[i]);
		}
		auto [f, c] = get_flow(n, n+1);
		if(f != w) return {-1, -1};
		forn(i, n) if(dd[i] != 0) g[i].pp();
		auto [ff, cc] = get_flow(s, t); g[s].pp(), g[t].pp();
		return {ff, c + cc + dc};
	}
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

	int n; cin>>n;
	vector<vector<int>> tipo(n, vector<int>(n)), costo(n, vector<int>(n));

	forn(i,n) forn(j,n) {
		cin>>tipo[i][j];
	}
	forn(i,n) forn(j,n) {
		cin>>costo[i][j];
		if (costo[i][j] == -1) costo[i][j] = INF;
	}

    return 0;
}

// https://codeforces.com/contest/277/problem/E
