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

#define node std::get<0>
#define weight std::get<1>
#define speed1 std::get<2>
#define speed2 std::get<3>

const ll N = 1e5+1;
const ll INF = 1e18;
ll n, m, t;

vector<tuple<ll,ll,ll,ll>> adj[N];
priority_queue<pair<ll,ll>> q;
ll dist[N];
bool processed[N];

void dijkstra() {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        processed[i] = false;
    }
    dist[1] = 0;
    q.push({0,1});
    while (!q.empty()) {
        ll a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            ll b = node(u), w = weight(u), s1 = speed1(u), s2 = speed2(u);
            

            ll time = w/s1 + t;
            if (dist[a] % time + w % s1 <= t) time += s1 - w % s1;
            else time += s2 - w % s2;
            if (dist[a] + time < dist[b]) {
                dist[b] = dist[a] + time;
                q.push({-dist[b], b});
            }
        }
    }
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>t;
    for (int i = 0; i < n; i++) {
        ll x, y, l, v, w; cin>>x>>y>>l>>v>>w;
        adj[x].push_back({y, l, v, w});
        adj[y].push_back({x, l, v, w});
    }

    dijkstra();
    cout<<dist[n]<<"\n";

    return 0;
}
