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

int n, m;
ll L, U;
const int N = 1e5+5;
const ll INF = 1e18;

vector<pair<int,ll>> adj[N];
vector<tuple<int,int,ll>> edges;
 
ll dist[N];
bool processed[N];
priority_queue<pair<ll,int>> q;

void dijkstra() {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        processed[i] = false;
    }
    dist[0] = 0LL;
    q.push({0,0});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.first; ll w = u.second;
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
            }
            q.push({-dist[b],b});
        }
    }
    for (int i = 0; i < n; i++) {
        dist[i] *= 2;
    }
}

bool alcanzable(tuple<int,int,ll>& e) {
    int a, b; ll w;
    tie(a,b,w) = e;
    if (dist[a] >= U and dist[b] >= U) return false;
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>L>>U;
    for (int i = 0; i < m; i++) {
        int a, b; ll w; cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
        edges.push_back({a,b,w});
    }

    dijkstra();

    int ans = 0;
    for (auto& e : edges) {
        if (alcanzable(e)) ans++;
    }
    cout<<ans<<"\n";

    return 0;
}
