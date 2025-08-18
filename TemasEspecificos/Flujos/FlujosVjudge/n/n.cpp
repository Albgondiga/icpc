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

struct Hopcroft{ // Matching maximo en bipartito en O(sqrt(n)*m)
	int n, m;
	vector<vector<int>> g;    // [0,n) -> [0,m)
	vector<int> mt, inv, ds;  // mt  : [0..n) -> [0..m) contiene el matching n-m
	                          // inv : [0..m) -> [0..n) contiene el matching inverso	
	void init(int n_, int m_) { n = n_, m = m_, g.resize(n_); }
	void add_edge(int u, int v) { g[u].push_back(v); }
	bool bfs(){
		ds.assign(n, -1); queue<int> q;
		forn(i, n) if(mt[i] < 0) ds[i] = 0, q.push(i);
		bool r = false;
		while(not q.empty()){
			int x = q.front(); q.pop();
			for(auto y : g[x]){
				if(inv[y] >= 0 and ds[inv[y]] < 0) ds[inv[y]] = ds[x]+1, q.push(inv[y]);
				else if(inv[y] < 0) r = true;
			}
		}
		return r;
	}
	bool dfs(int x){
		for(auto y : g[x]) if(inv[y] < 0 or (ds[inv[y]] == ds[x]+1 and dfs(inv[y]))){
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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    Hopcroft h; h.init(n, n);
    for (int u = 0; u < n; u++) {
        int k; cin>>k;
        for (int i = 0; i < k; i++) {
            int v; cin>>v;
            h.add_edge(u,v);
        }
    }
    cout<<n-h.mm()<<"\n";

    return 0;
}
