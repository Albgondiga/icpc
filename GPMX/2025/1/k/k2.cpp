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

// https://codeforces.com/gym/105873/problem/K

vector<bool> visited; // keeps track of which vertices are already visited

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
void strongly_connected_components(vector<vector<int>> const& adj,
                                  vector<vector<int>> &components,
                                  vector<vector<int>> &adj_cond) {
    int N = adj.size();
    components.clear(), adj_cond.clear();

    vector<int> order; // will be a sorted list of G's vertices by exit time

    visited.assign(N, false);

    // first series of depth first searches
    for (int i = 0; i < N; i++)
        if (!visited[i])
            dfs(i, adj, order);

    // create adjacency list of G^T
    vector<vector<int>> adj_rev(N);
    for (int v = 0; v < N; v++)
        for (int u : adj[v])
            adj_rev[u].push_back(v);

    visited.assign(N, false);
    reverse(order.begin(), order.end());

    vector<int> roots(N, 0); // gives the root vertex of a vertex's SCC

    // second series of depth first searches
    for (auto v : order)
        if (!visited[v]) {
            std::vector<int> component;
            dfs(v, adj_rev, component);
            components.push_back(component);
            int root = *min_element(begin(component), end(component));
            for (auto u : component)
                roots[u] = root;
        }

    // add edges to condensation graph
    adj_cond.assign(N, {});
    for (int v = 0; v < N; v++)
        for (auto u : adj[v])
            if (roots[v] != roots[u])
                adj_cond[roots[v]].push_back(roots[u]);
}

// Dinic
const ll INF = 1e18;
vector<int> costo_scc;
struct Dinic {
    int src,dst;
    vector<int>dist,q,work;
    struct edge{int to,rev;ll f,cap;};
    vector<vector<edge>> G;
    Dinic (int x):G(x),dist(x),q(x),work(x){}
    void add_edge(int s, int t, ll cap){
        G[s].push_back({t,(int)G[t].size(),0,cap});
        G[t].push_back({s,(int)G[s].size()-1,0,0});
    }
    bool dinic_bfs(){
        fill(dist.begin(), dist.end(),-1);dist[src]=0;
        int qt=0;q[qt++]=src;
        for(int qh=0;qh<qt;qh++){
            int u=q[qh];
            for(int i = 0; i < (int)G[u].size(); i++){
                edge &e=G[u][i];int v=G[u][i].to;
                if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
            }
        }
        return dist[dst]>=0;
    }
    ll dinic_dfs(int u, ll f){
        if(u==dst)return f;
        for(int &i=work[u];i<(int)G[u].size();i++){
            edge &e=G[u][i];
            if(e.cap<=e.f)continue;
            int v=e.to;
            if(dist[v]==dist[u]+1){
                ll df=dinic_dfs(v,min(f,e.cap-e.f));
                if(df>0){e.f+=df;G[v][e.rev].f-=df;return df;}
            }
        }
        return 0;
    }
    ll max_flow(int _src, int _dst){
        src=_src,dst=_dst;
        ll result=0;
        while(dinic_bfs()){
            fill(work.begin(), work.end(),0);
            while(ll delta=dinic_dfs(src,INF))result+=delta;
        }
        return result;
    }
    // Especifico del problema
    int max_closure() {
        vector<bool> visited(G.size(), false);
        queue<int> q;
        q.push(src);
        visited[src] = true;
        int ans = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (const edge& e : G[u]) {
                if (!visited[e.to] and e.f >= 0) {
                    visited[e.to] = true;
                    q.push(e.to);
                    ans += costo_scc[e.to];
                }
            }
        }
        return ans;
    }
    
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m; cin>>n>>m;

    vector<int> costo(n);
    vector<vector<int>> adj(n), components, adj_cond;

    for (int i = 0; i < n; i++) {
        cin>>costo[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
    }

    strongly_connected_components(adj,components,adj_cond);
    for (int i = 0; i < components.size(); i++) {
        int s = 0;
        for (int j = 0; j < components[i].size(); j++) {
            s += costo[components[i][j]];
        }
        costo_scc.push_back(s);
    }

    Dinic dinic(components.size()+2);
    for (int u = 0; u < adj_cond.size(); u++) {
        for (int& v : adj_cond[u]) {
            dinic.add_edge(u,v,INF);
        }
    }

    // src es n, dst es n+1
    for (int u = 0; u < components.size(); u++) {
        if (costo_scc[u] >= 0) dinic.add_edge(n, u, costo_scc[u]);
        else dinic.add_edge(u,n+1,-costo_scc[u]);
    }

    dinic.max_flow(n,n+1);
    cout<<dinic.max_closure()<<endl;

    return 0;
}
