// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 1
#define ifd if (debug)

const int N = 1e5+1;
int n, r;
map<pair<int,int>,ll> costoArista;
vector<tuple<int,int,ll>> edges;

// --- DSU / UF ---
int link[N];
int sizes[N];

int find(int x) {
    while (x != link[x]) x = link[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (sizes[a] < sizes[b]) swap(a,b);
    sizes[a] += sizes[b];
    link[b] = a;
}
// ------

// --- Código para inicializar up[][] y maxArista[][] ---

vector<pair<int,ll>> adj[N];
vector<vector<int>> up, maxArista;
vector<int> tin, tout;
const int LOG = 20;
int timer;

void dfs(int v, int p, ll c) {
    tin[v] = ++timer;
    up[v][0] = p;
    maxArista[v][0] = c;

    for (int i = 1; i <= LOG; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
        maxArista[v][i] = max(maxArista[v][i-1], maxArista[up[v][i-1]][i-1]);
    }

    for (auto u : adj[v]) {
        if (u.first != p) {
            dfs(u.first, v, u.second);
        }
    }
    tout[v]= ++timer;
}

void preprocess(int root) {
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    up.assign(n+1, vector<int>(LOG+1));
    maxArista.assign(n+1, vector<int>(LOG+1));
    for (int i = 1; i <= LOG; i++) {
        maxArista[1][i] = 0;
    }
    dfs(1,1,0);
}
// -------

bool isAncestor(int u, int v) {
    return (tin[u] <= tin[v]) and (tout[u] >= tout[v]);
}

// Retorna la arista más pesada desde u a lca(u,v)
int lca(int u, int v) {
    bool subir = true;
    if (isAncestor(u,v)) subir = false;
    int arista = 0;
    for (int i = LOG; i >= 0; i--) {
        if (!isAncestor(up[u][i],v)) {
            arista = max(arista, maxArista[u][i]);
            u = up[u][i];
        }
    }
    if (subir) arista = max(arista, maxArista[u][0]);
    return arista;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>r;
    forn(i,r) {
        int a, b; ll c; cin>>a>>b>>c;
        edges.push_back({c,a,b});
        edges.push_back({c,b,a});
        if (a>b) swap(a,b);
        costoArista[{a,b}] = c;
    }

    for (int i = 1; i <= n; i++) link[i] = i;
    for (int i = 1; i <= n; i++) sizes[i] = 1;

    // Calcular MST
    ll costo = 0;
    set<pair<int,int>> arbol;
    sort(edges.begin(), edges.end());
    for (auto e : edges) {
        int a, b; ll c;
        tie(c,a,b) = e;
        if (!same(a,b)) {
            costo += c;
            unite(a,b);
            if (a > b) swap(a,b);
            arbol.insert({a,b});
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
    }

    preprocess(1);

    int q; cin>>q;
    while (q--) {
        int u, v; cin>>u>>v;
        if (u>v) swap(u,v);
        // Si la arista ya esta en el arbol, la respuesta es el peso del arbol
        if (arbol.find({u,v}) != arbol.end()) {
            cout<<costo<<"\n";
        } else {
            // Si no esta, se encuentra la arista mas pesada de u y v a lca(u,v) 
            // y se reemplaza
            int arista = max(lca(u,v), lca(v,u));
            ll costo2 = costo;
            costo2 -= arista;
            costo2 += costoArista[{u,v}];
            cout<<costo2<<"\n";
        }
    }

    return 0;
}
