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
const int N = 1e5+1;
int n, m;
vector<pair<int,ll>> adj[N];
ll dist[N];
bool processed[N];
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
 
    cin>>n>>m;
    forn(i,m) {
        ll a, b, c; cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
 
    priority_queue<pair<ll,int>> q;
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[1] = 0;
    q.push({0,1});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.first; ll c = u.second;
            if (dist[a]+c < dist[b]) {
                dist[b] = dist[a]+c;
                q.push({-dist[b],b});
            }
        }
    }
 
    for (int i = 1; i <= n; i++) cout<<dist[i]<<" ";
    cout<<"\n";
 
    return 0;
}
