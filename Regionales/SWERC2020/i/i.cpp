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

const int N = 1e5+5;
int n, m;
vector<int> adj[N];

bool visited[N];
int dist[N];

void dfs(int v) {
    if (visited[v]) return;
    visited[v] = true;
    for (int u : adj[v]) {
        dfs(u);
    }
}

// nodo, dist
pair<int,int> bfs(int v) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        dist[i] = 0;
    }
    pair<int,int> ans = {0,0};
    visited[v] = true;
    q.push(v);
    while(!q.empty()) {
        int s = q.front(); q.pop();
        for (int u : adj[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            dist[u] = dist[s]+1;
            if (dist[u] > ans.second)
                ans = {u,dist[u]};
            q.push(u);
        }
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) visited[i] = false;
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout<<-1<<"\n";
            return 0;
        }
    }

    pair<int,int> u1 = bfs(1);
    pair<int,int> u2 = bfs(u1.first);
    cout<<(int)log2(u2.second)+1<<"\n";

    return 0;
}
