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
const ll N = 501;
ll n, m;
ll capacity[N][N] = {0};
vector<ll> adj[N];

ll bfs(ll s, ll t, vector<ll>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    // <node, max flow possible till now>
    queue<pair<ll, ll>> q;
    q.push({s, INF});

    while (!q.empty()) {
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (ll next : adj[cur]) {
            // Si no he visto a next y todavia tiene capacidad
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

ll maxflow(ll s, ll t) {
    ll flow = 0;
    vector<ll> parent(N);
    ll new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        ll cur = t;
        while (cur != s) {
            ll prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

// Perform a BFS to mark all nodes reachable from source in the residual graph
bool visited[N];
void dfs(ll v) {
    if (visited[v]) return;
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u] and capacity[v][u] > 0) {
            dfs(u);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    ll a, b;
    forn(i,m) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        capacity[a][b] = capacity[b][a] = 1;
    }

    maxflow(1,n);
    dfs(1);

    vector<ii> ans;
    for (int v = 1; v <= n; v++) {
        for (auto u : adj[v]) {
            if (visited[v] and !visited[u] and capacity[v][u] == 0) {
                ans.push_back({v,u});
            }
        }
    }

    cout<<ans.size()<<"\n";
    for (auto i : ans) {
        cout<<i.first<<" "<<i.second<<"\n";
    }
    

    return 0;
}
