// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<ll, ll> ii;

#define debug 0
#define ifd if (debug)

const ll INF = 1e18;
int n, k, respaldo;

// Nodo para abajo de mi mas lejano, guardia para abajo mas cerca mio
vector<ll> lejano, guardia;
vector<vector<int>> adj;

void dfs(int v, ll R, int p = -1) {
    bool hoja = true;
    for (int u : adj[v]) {
        if (u == p) continue;
        hoja = false;
        dfs(u, R, v);

        if (lejano[u] != -INF) lejano[v] = max(lejano[v], lejano[u]+1);
        if (guardia[u] != INF) guardia[v] = min(guardia[v], guardia[u]+1);
    }
     
    // Podo el arbol. 
    // Una hoja es literalmente una hoja o un primer nodo inalcanzable en una rama
    if (hoja or (guardia[v] > R and lejano[v] == -INF)) {
        lejano[v] = max(lejano[v], 0LL);
        guardia[v] = INF;
        return;
    }
    
    if (guardia[v] != INF and lejano[v] != -INF and (lejano[v] + guardia[v] <= R)) {  
        // Si el nodo lejano es alcanzable por un guardia que ya existe, todos son alcanzables
        lejano[v] = -INF;
        return;
    }
    
    if (lejano[v] == R) {
        // De fijo tengo que poner un mae aqui
        k--;
        lejano[v] = -INF;
        guardia[v] = 0;
    }
}

bool check(ll m) {
    k = respaldo;
    if (m == 0) return (k >= n);

    dfs(1,m);
    if (lejano[1] != -INF) k--;
    
    if (k >= 0) return true;
    return false;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while(tC--) {
        cin>>n>>k;
        respaldo = k;
        adj.assign(n+1, vector<int>());
        
        forn(i,n-1) {
            int u, v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        ll l = -1, r = 1e8, ans = -1;
        while (r-l>1) {
            ll m = l + (r-l)/2;
            lejano.assign(n+1, -INF), guardia.assign(n+1, INF);
            if (check(m)) {
                r = m;
            } else {
                l = m;
            }
        }

        cout<<r<<"\n";
    }

    return 0;
}
