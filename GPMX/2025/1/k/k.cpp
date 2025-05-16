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

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

// Kosaraju
// necesita el grafo en g y el grafo reverso en gr. En comp te dice para cada vertice a 
// que componente fuertemente conexa pertenece. En gcc te deja el DAG de componentes 
// fuertemente conexas (este puede tener aristas repetidas, si hay mas de una que va de la componente x a la y)
int n,m; 
vvi g,gr,gcc;
vb visitado; 
vi comp, orden, costo, costo_gcc;

void dfs1(int v){
    if (visitado[v]) return;
    visitado[v] = true;
    for (auto u : gr[v]) dfs1(u);
    orden.push_back(v); 
}
void dfs2(int v, int c){
    comp[v] = c;
    costo_gcc[c] += costo[v];
    for (auto u : g[v]) {
        if (comp[u] == -1) dfs2(u,c);
        else if (comp[u] != c) gcc[c].push_back(comp[u]);
    }
}
void scc(){
    visitado = vb(n,false); 
    for (int i = 0; i < n; i++) dfs1(i);
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (comp[orden[i]] != -1) continue;
        ifd cout<<orden[i]<<" define un nuevo componente "<<endl;
        gcc.push_back({});
        costo_gcc.push_back(0);
        dfs2 (orden[i],c); 
        c++;
    } 
}

// Dinic
// const ll INF = 1e18;
// struct Dinic {
//     int src,dst;
//     vector<int>dist,q,work;
//     struct edge{int to,rev;ll f,cap;};
//     vector<vector<edge>> G;
//     Dinic (int x):G(x),dist(x),q(x),work(x){}
//     void add_edge(int s, int t, ll cap){
//         G[s].push_back({t,(int)G[t].size(),0,cap});
//         G[t].push_back({s,(int)G[s].size()-1,0,0});
//     }
//     bool dinic_bfs(){
//         fill(dist.begin(), dist.end(),-1);dist[src]=0;
//         int qt=0;q[qt++]=src;
//         for(int qh=0;qh<qt;qh++){
//             int u=q[qh];
//             for(int i = 0; i < (int)G[u].size(); i++){
//                 edge &e=G[u][i];int v=G[u][i].to;
//                 if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
//             }
//         }
//         return dist[dst]>=0;
//     }
//     ll dinic_dfs(int u, ll f){
//         if(u==dst)return f;
//         for(int &i=work[u];i<(int)G[u].size();i++){
//             edge &e=G[u][i];
//             if(e.cap<=e.f)continue;
//             int v=e.to;
//             if(dist[v]==dist[u]+1){
//                 ll df=dinic_dfs(v,min(f,e.cap-e.f));
//                 if(df>0){e.f+=df;G[v][e.rev].f-=df;return df;}
//             }
//         }
//         return 0;
//     }
//     ll max_flow(int _src, int _dst){
//         src=_src,dst=_dst;
//         ll result=0;
//         while(dinic_bfs()){
//             fill(work.begin(), work.end(),0);
//             while(ll delta=dinic_dfs(src,INF))result+=delta;
//         }
//         return result;
//     }
//     // Especifico del problema
//     int max_closure() {
//         vector<bool> visited(G.size(), false);
//         queue<int> q;
//         q.push(src);
//         visited[src] = true;
//         int ans = 0;
//         while (!q.empty()) {
//             int u = q.front(); q.pop();
//             for (const edge& e : G[u]) {
//                 if (!visited[e.to] and e.f < e.cap) {
//                     visited[e.to] = true;
//                     q.push(e.to);
//                     ans += costo_gcc[e.to];
//                 }
//             }
//         }
//         return ans;
//     }
    
// };

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    comp.assign(n,-1), costo.resize(n), g.resize(n), gr.resize(n);

    for (int i = 0; i < n; i++) {
        cin>>costo[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        u--, v--;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    scc();

    ifd {
        cout<<"Hay "<<gcc.size()<<" cc de pesos ";
        for (int& x : costo_gcc) cout<<x<<" ";
        cout<<endl;
        for (int i = 0; i < n; i++) {
            cout<<"El comp de "<<i<<" es "<<comp[i]<<endl;
        }
    }

    // ifd cout<<"Sigue Dinic"<<endl;
    // Dinic dinic(gcc.size()+2);
    // for (int u = 0; u < gcc.size(); u++) {
    //     for (int& v : gcc[u]) {
    //         dinic.add_edge(u,v,INF);
    //     }
    // }
    // // src es n, dst es n+1
    // for (int u = 0; u < gcc.size(); u++) {
    //     if (costo[u] >= 0) dinic.add_edge(n, u, costo[u]);
    //     else dinic.add_edge(u,n+1,-costo[u]);
    // }

    // cout<<dinic.max_closure()<<endl;

    return 0;
}
