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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

const int N = 2e5+1;
int n;
vector<int> adj[N];
ll ans[N], sz[N];

// Calcula sz[] y la suma de profundidades (respuesta de la raíz)
void dfs1(int u, int p, int prof) {
    sz[u] = 1;
    ans[1] += prof;
    for (int c : adj[u]) {
        if (c == p) continue;
        dfs1(c, u, prof + 1);
        sz[u] += sz[c];
    }
}

// Mueve la raíz de u a cada hijo c
void dfs2(int u, int p) {
    for (int c : adj[u]) {
        if (c == p) continue;
        /**
         * La distancia n - sz[c] nodos que no estan en el subarbol de c aumenta en 1
         * La distancia de los nodos que estan en el subarbol de c disminuye en 1
         */
        ans[c] = ans[u] - sz[c] + (n - sz[c]);
        dfs2(c, u);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

	cin>>n;
	forn(i,n-1) {
		int u, v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

    dfs1(1, 0, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) cout<<ans[i]<<" ";

    return 0;
}
