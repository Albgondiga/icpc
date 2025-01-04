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

#define debug 0
#define ifd if (debug)

const int N = 5*1e5+1;
const ll INF = 1e18;
int n, m, t;
vector<pair<int,ll>> adj[N];
ll dist[N];
bool processed[N];

void dijkstra(ll mid) {
    priority_queue<pair<ll,int>> q;
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        processed[i] = false;
    }
    dist[1] = 0;
    q.push({0,1});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.first;
            ll w = u.second;
            if ((w >= mid) && (dist[a]+w < dist[b])) {
                dist[b] = dist[a]+w;
                q.push({-dist[b],b});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>t;
    forn(i,m) {
        ll u, v, t2; cin>>u>>v>>t2;
        adj[u].push_back({v,t2});
        adj[v].push_back({u,t2});
    }

    ll l = 1, r = 6*1e5;
    ll ans = 0;
    while (l <= r) {
        ll mid = l+(r-l)/2;
        ifd cout<<"l = "<<l<<", r = "<<r<<", mid = "<<mid<<endl;
        dijkstra(mid);
        ifd cout<<"dist[n] = "<<dist[n]<<endl<<endl;
        if (dist[n] <= t) {
            l = mid+1; ans = mid;
        } else {
            r = mid-1;
        }
    }

    ifd cout<<"ans = "<<ans<<endl;
    dijkstra(ans);
    if (dist[n] <= t) cout<<ans<<'\n';
    else cout<<"He is taking an uber.\n";

    return 0;
}
