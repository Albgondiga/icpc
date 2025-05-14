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

vector<bool> visited; // keeps track of which vertices are already visited
vector<vector<int>> adj;
vector<vector<int>> components;
vector<vector<int>> adj_cond;
vector<vector<int>> adj_cond_rev;

vector<int> costo;
vector<int> ganancia;
vector<int> costoCond;
vector<int> inGrado;
vector<int> inGradoCond;

// runs depth first search starting at vertex v.
// each visited vertex is appended to the output vector when dfs leaves it.
void dfs(int v, vector<vector<int>> const& adj, vector<int> &output) {
    visited[v] = true;
    for (auto u : adj[v])
        if (!visited[u])
            dfs(u, adj, output);
    output.push_back(v);
}

// input: adj -- adjacency list of G
// output: components -- the strongy connected components in G
// output: adj_cond -- adjacency list of G^SCC (by root vertices)
void strongly_connected_components() {
    int n = adj.size();
    components.clear(), adj_cond.clear();

    vector<int> order; // will be a sorted list of G's vertices by exit time

    visited.assign(n, false);

    // first series of depth first searches
    for (int i = 1; i < n; i++)
        if (!visited[i])
            dfs(i, adj, order);

    // create adjacency list of G^T
    vector<vector<int>> adj_rev(n);
    for (int v = 1; v < n; v++)
        for (int u : adj[v])
            adj_rev[u].push_back(v);

    visited.assign(n, false);
    reverse(order.begin(), order.end());

    vector<int> roots(n, 0); // gives the root vertex of a vertex's SCC

    int root = 1;
    costoCond.push_back(0);
    // second series of depth first searches
    for (auto v : order)
        if (!visited[v]) {
            std::vector<int> component;
            dfs(v, adj_rev, component);
            components.push_back(component);
            //int root = *min_element(begin(component), end(component));
            costoCond.push_back(0);
            for (auto u : component) {
                roots[u] = root;
                costoCond[root] += costo[u];
            }
            root++;
        }

    // add edges to condensation graph
    adj_cond.assign(root, {});
    for (int v = 1; v < n; v++)
        for (auto u : adj[v])
            if (roots[v] != roots[u])
                adj_cond[roots[v]].push_back(roots[u]);
}

void dfsCostoAcumulado(int v, int suma) {
    if (visited[v]) return;
    visited[v] = true;
    ganancia[v] = suma + costo[v];
    for (int u : adj_cond[v]) {
        dfsCostoAcumulado(u, ganancia[v]);
    }
}

int dfsMaximos(int v) {
    if (visited[v]) return;
    visited[v] = true;
    int maximo = 0;
    for (int u : adj_cond[v]) {
        maximo = max(maximo, dfsMaximos(u));
    }
    return maximo;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    adj.resize(n+1), costo.resize(n+1), ganancia.resize(n+1);
    inGrado.assign(n+1,0);

    for (int i = 1; i <= n ; i++) {
        cin>>costo[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        inGrado[b]++;
    }

    // Encuentro el costo acumulado de cada nodo
    for (int v = 1; v <= n; v++) {
        if (inGrado[v] == 0) 
    }

    // Encuentro las componentes
    strongly_connected_components();
    // Guardo el grafo de componentes invertido
    n = adj_cond.size();
    for (int v = 1; v < n; v++)
        for (int u : adj_cond[v])
            adj_cond_rev[u].push_back(v);

    vector<int> costo(n);
    vector<int> ganancia(n);
    vector<int> costoCond(n);
    for ()


    return 0;
}
