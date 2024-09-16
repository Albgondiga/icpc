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

const ll INF = 1e18;
const int N = 1e5+1;
int n, m;
vector<pair<int,ll>> adj[N];
bool visited[N];

// Costo y tiquete mas caro
vector<pair<ll,ll>> routes;

void dfs(int s, ll w, ll ticket) {
    if (visited[s]) {
        ifd if (s == n) cout<<"Llegue a "<<s<<" con w = "<<w<<" y ticket = "<<ticket<<endl;
        if (s == n) {
            routes.push_back({w,ticket});
            return;
        }
        return;
    }
    visited[s] = true;
    for (auto u : adj[s]) {
        ifd cout<<"Voy hacia "<<u.first<<" desde "<<s<<endl;
        dfs(u.first, w+u.second, max(ticket,u.second));
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    forn(i,m) {
        int a, b; ll w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
    }

    visited[n] = true;
    dfs(1,0,0);

    ifd {
        cout<<"Rutas:"<<endl;
        for (auto r : routes) {
            cout<<r.first<<" "<<r.second<<endl;
        }
    }

    ll ans = INF;
    for (auto r : routes) {
        ans = min(ans, r.first-(r.second-r.second/2));
    }
    cout<<ans<<"\n";
    return 0;
}
