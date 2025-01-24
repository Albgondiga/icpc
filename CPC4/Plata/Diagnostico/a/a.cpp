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

const ll INF = 1e18;
int J, B, C, N, S;

void dijkstra(int x, vector<ll>& dist, vector<vector<pair<int,ll>>>& adj) {
    priority_queue<pair<ll,int>> q;
    vector<bool> processed(J+1);
    for (int i = 1; i <= J; i++) {
        dist[i] = INF;
        processed[i] = false;
    }

    dist[x] = 0;
    q.push({0,x});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.first; ll w = u.second;
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push({-dist[b],b});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while (cin>>J>>B>>C>>N>>S) {
        if (J == -1) return 0;
        vector<vector<pair<int,ll>>> adj(J+1);
        forn(i,S) {
            int a, b; ll w; cin>>a>>b>>w;
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }

        vector<ll> distB(J+1), distC(J+1), distN(J+1);
        dijkstra(B, distB, adj);
        dijkstra(C, distC, adj);
        dijkstra(N, distN, adj);

        ll t = 0, c = distB[C], n = distB[N];
        for(int i = 1; i <= J; i++) {
            if ((distB[i] + distC[i] == distB[C]) and (distB[i] + distN[i] == distB[N])) {
                t = max(t, distB[i]);
            }
        }
        c -= t; 
        n -= t;
        cout<<t<<" "<<c<<" "<<n<<"\n";
    }
    return 0;
}
