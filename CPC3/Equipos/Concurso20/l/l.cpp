#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef long double ld;
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
const ld INF = 1e18;
ll n, m;
ld t;

vector<tuple<ll,ld,ld,ld>> adj[N];
priority_queue<pair<ld,ll>> q;
ld dist[N];
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
            ll b = node(u); ld w = weight(u), s1 = speed1(u), s2 = speed2(u);
            if (dist[a] >= t) {
                if (dist[a] + w/s2 < dist[b]) {
                    dist[b] = dist[a] + w/s2;
                    q.push({-dist[b], b});
                }
            } else if (dist[a] + w/s1 <= t) {
                if (dist[a] + w/s1 < dist[b]) {
                    dist[b] = dist[a] + w/s1;
                    q.push({-dist[b], b});
                }
            } else { // dist[a] + w/s1 > t
                ld dist_s1 = (t-dist[a])*s1;
                ld dist_s2 = w - dist_s1;
                if (t + dist_s2/s2 < dist[b]) {
                    dist[b] = t + dist_s2/s2;
                    q.push({-dist[b], b});
                }    
            }     
        }
    }
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>t;
    for (int i = 0; i < m; i++) {
        ll x, y; ld l, v, w; cin>>x>>y>>l>>v>>w;
        adj[x].push_back({y, l, v, w});
        adj[y].push_back({x, l, v, w});
    }

    dijkstra();
    cout<<setprecision(6)<<fixed;
    cout<<dist[n]<<"\n";

    return 0;
}
