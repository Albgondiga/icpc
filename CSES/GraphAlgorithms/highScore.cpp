#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define pf push_front
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef pair<ll,ll> pll;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

const ll INF = 1e18;
const int N = 2501;
int n, m;

void dfs(int s, bool* visited, vector<vector<int>>& adj) {
    if (visited[s]) return;
    visited[s] = true;
    for (auto u : adj[s]) {
        dfs(u, visited, adj);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    vector<vector<int>> adj(N);
    vector<vector<int>> adjBackwards(N);
    vector<tuple<int,int,ll>> edges;
    forn(i,m) {
        int a, b; ll w;
        cin>>a>>b>>w;
        adj[a].push_back(b);
        adjBackwards[b].push_back(a);
        edges.push_back({a,b,w*-1});
    }
    
    // Esto me dice si 1 es parte del ciclo o no
    bool visited[N] = {0};
    bool visitedBackwards[N] = {0};
    dfs(1,visited,adj);
    dfs(n,visitedBackwards,adjBackwards);

    ll dist[N];
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[1] = 0;
    bool cycle = 0;
    for (int i = 1; i <= n; i++) {
        for (auto e : edges) {
            int a, b; ll w;
            tie(a,b,w) = e;
            if (dist[a]+w < dist[b]) {
                if (i == n and visited[a] and visitedBackwards[a]) cycle = 1;
                else dist[b] = dist[a]+w;
            }
        }
    }

    if (cycle) cout<<-1<<"\n";
    else cout<<dist[n]*-1<<"\n";
    
    return 0;
}
