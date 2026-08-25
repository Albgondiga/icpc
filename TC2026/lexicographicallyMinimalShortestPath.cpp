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

// https://codeforces.com/group/GHvtTrfZFd/contest/706415/problem/H

typedef pair<int,char> edge;

const int N = 2e5+1;
vector<edge> adj[N];

void bfs(int x, vector<int>& dist) {
    vector<bool> vis(N,false);
    queue<int> q;
    vis[x] = true; 
    dist[x] = 0; 
    q.push(x); 
    while (!q.empty()) { 
        int s = q.front(); q.pop(); 
        // process node s 
        for (auto e : adj[s]) {
            int u;
            tie(u,ignore) = e;
            if (vis[u]) continue; 
            vis[u] = true; 
            dist[u] = dist[s]+1; 
            q.push(u); 
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m; cin>>n>>m;

    forn(i,m) {
        int u, v; char c; cin>>u>>v>>c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    vector<int> dist1(n+1, 1e7), dist2(n+1, 1e7);
    bfs(1, dist1);  // desde 1
    bfs(n, dist2);  // desde n

    vector<int> path, p(n+1,-1), cur = {1};
    string ans = "";

    while (cur.front() != n) {
        vector<int> next;
        // Buscar char optimo
        char mini = 'z' + 1;
        for (int u : cur) {
            for (auto e : adj[u]) {
                int v; char c;
                tie(v,c) = e; 
                if (c < mini and dist1[u] + 1 == dist1[v] and dist1[v] + dist2[v] == dist1[n]) {
                    mini = c;
                }
            }
        }
        // Avanzar
        for (int u : cur) {
            for (auto e : adj[u]) {
                int v; char c;
                tie(v,c) = e; 
                if (c == mini and dist1[u] + 1 == dist1[v] and dist1[v] + dist2[v] == dist1[n]) {
                    if (p[v] == -1) {
                        p[v] = u;
                        next.push_back(v);
                    }
                }
            }
        }
        ans.push_back(mini);
        cur = next;
    }

    cout<<dist1[n]<<"\n";
    int v = n;
    while (v != 1) {
        path.push_back(v);
        v = p[v];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    for (int v : path) cout<<v<<" ";
    cout<<"\n";
    cout<<ans<<"\n";

    return 0;
}
