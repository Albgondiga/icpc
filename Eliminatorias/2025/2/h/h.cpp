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

const int N = 1e4;
int n;
ll h, k;

vector<vector<int>> adj;
vector<pair<ll,ll>> coord;
vector<int> rod;
map<pair<ll,ll>, int> indice;

ll bfs(int x) {
    pair<ll,ll> coso = coord[x];
    if (rod[x] and coso.second*coso.second <= h) {
        return 1;
    }
    queue<int> q;
    vector<int> visited(n);
    vector<ll> dist(n);
    visited[x] = true;
    dist[x] = 0;
    q.push(x);

    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto u : adj[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            dist[u] = dist[s] + 1;
            q.push(u);

            pair<ll,ll> coso = coord[u];
            if (rod[u] and coso.second*coso.second <= h) {
                return dist[u] + !(coso.second == 0);
            }
        }
    }

    return -1;
} 

ll euclidiana(int u, int v) {
    pair<ll,ll> c1 = coord[u], c2 = coord[v];
    return ((c1.first-c2.first)*(c1.first-c2.first) + (c1.second-c2.second)*(c1.second-c2.second)); 
}

bool son_adyacentes(int u, int v) {
    if (rod[u]) {
        if (rod[v]) {
            if (euclidiana(u,v) <= min(h,k)) return true;
        } else {
            if (euclidiana(u,v) <= h) return true;
        }
    } else {
        if (rod[v]) {
            if (euclidiana(u,v) <= k) return true;
        }
    }
    return false;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>h>>k;
    ll ans = -1;
    k *= k;
    h *= h;

    adj.resize(n);
    coord.resize(n);
    rod.resize(n);

    for (int i = 0; i < n; i++) {
        ll a, b; int x; cin>>a>>b>>x;
        rod[i] = x;
        coord[i] = {a,b};
        indice[{a,b}] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (son_adyacentes(i,j)) adj[i].push_back(j);
            if (son_adyacentes(j,i)) adj[j].push_back(i);
        }
    }

    ll a, b; cin>>a>>b;
    if (b == 0) {
        cout<<0<<"\n";
        return 0;
    }

    pair<ll,ll> x = {a,b};
    cout<<bfs(indice[{a,b}])<<"\n";

    return 0;
}
