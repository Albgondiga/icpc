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

const int N = 1e6+5;

// Tarjan
vector<int> g[N];     
int vis[N];
int low[N], scc[N], mi[N];  //Inicializar en -1
int idx = 0, cant = 1;
stack<int> s;
void dfs(int v){
	vis[v] = 1;
	int tag = low[v] = idx ++;
	s.push(v);
	for (auto x : g[v]){
		if(vis[x] and scc[x] > -1) continue;
		if(not vis[x]) dfs(x);
		low[v] = min(low[v], low[x]);
	}
	if (low[v] == tag){
		while (1){
			int x = s.top(); s.pop();
			scc[x] = cant;
			if(x == v) break;
		}
		cant++;
	}
}

vector<int> orden;
vector<int> adj[N];
ll valor[N], ganancia[N], ans[N];
void topo(int v) {
    vis[v] = 1;
    for (auto u : adj[v]) {
        if (!vis[u]) topo(u);
    }
    vis[v] = 2;
    orden.push_back(v);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m, s, e; cin>>n>>m>>s>>e;
    for (int i = 1; i <= n; i++) {
        cin>>valor[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        g[a].push_back(b);
    }

    // Tarjan
    for (int i = 1; i <= n; i++) scc[i] = -1;

    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);

    for (int i = 1; i <= n; i++) mi[i] = -1;

    int n2 = 0;
    for (int i = 1; i <= n; i++) {
        if (mi[scc[i]] != -1) {
            scc[i] = mi[scc[i]];
        } 
        else {
            mi[scc[i]] = i, scc[i] = i;
        }
        // Se le suma la gannacia al representante
        ganancia[scc[i]] += valor[i];  
        n2 = max(n2, scc[i]);
    }

    // Nuevo DAG
    for (int u = 1; u <= n; u++) {
        for (int v : g[u]) {
            if (scc[u] != scc[v]) adj[scc[u]].push_back(scc[v]);
        }
    }

    // Orden topologico
    for (int i = 1; i <= n2; i++) {
        vis[i] = 0;
        ans[i] = ganancia[i];
    }
    for (int i = 1; i <= n2; i++) if (!vis[i]) topo(i);
    reverse(orden.begin(), orden.end());

    // Se calcula la ganancia maxima sobre el orden a partir de s
    bool found = false;
    for (int u : orden) {
        if (u == scc[s]) found = true;
        if (!found) continue;

        for (int v : adj[u]) {
            ans[v] = max(ans[v], ans[u] + ganancia[v]);
        }
    }
    cout<<ans[scc[e]]<<"\n";

    return 0;
}
