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

pair<int, int> bfs(int start, vector<vector<int>>& adj) {
    vector<int> dist(adj.size(), -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int farthest_node = start;
    int max_distance = 0;

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : adj[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v]+1;
                q.push(u);
                if (dist[u] > max_distance) {
                    max_distance = dist[u];
                    farthest_node = u;
                }
            }
        }
    }
    return {farthest_node, max_distance};
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    while (n != -1) {
        vector<vector<int>> adj(n+1, vector<int>());
        for (int i = 2; i <= n; i++) {
            int x; cin>>x;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }

        pair<int,int> b = bfs(1, adj);
        pair<int,int> c = bfs(b.first, adj);
        int diameter = c.second;

        cout<<c.second/2+((c.second % 2) ? 1: 0)<<"\n";

        cin>>n;
    }

    return 0;
}
