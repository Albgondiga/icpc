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

const int N = 10000;
const ll INF = 1e18;
int n, m;
vector<pair<int,ll>> adj[N];
vector<tuple<int,int,ll>> edges;

void dijkstra(int x, ll* dist) {
    priority_queue<pair<ll,int>> q;
    bool processed[n];
    forn(i,n) {
        processed[i] = false;
        dist[i] = INF;
    }
    dist[x] = 0;
    q.push({0,x});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.first; ll w = u.second;
            if (dist[a]+w < dist[b]) {
                dist[b] = dist[a]+w;
                q.push({-dist[b],b});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    int a, b; ll w;
    forn(i,m) {
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
        edges.push_back({a,b,w});
    }

    ll dist0[n];
    ll distN[n];

    dijkstra(0, dist0);
    dijkstra(n-1, distN);

    ll cost = 0;
    for (auto e : edges) {
        tie(a,b,w) = e;
        if ((dist0[a]+w+distN[b] == dist0[n-1]) or (dist0[b]+w+distN[a] == dist0[n-1])) {
            cost += (w*2);
        }
    }
    cout<<cost<<"\n";

    return 0;
}
