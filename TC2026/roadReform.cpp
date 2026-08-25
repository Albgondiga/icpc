#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define fst first
#define snd second
#define fore(e,c) for(const auto &e : (c))
typedef long long ll;
typedef pair<ll, ll> ii;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

const int N = 2e5+1;
ll n, m, k;
vector<tuple<ll,ll,ll>> edges;

ll p[N], r[N];
bool vis[N];

int find(int a) {
    if (p[a] != a) p[a] = find(p[a]);
    return p[a];
}

bool same(int a, int b) { 
    return find(a) == find(b);
}

void unite(int a, int b) {
    if (same(a,b)) return;
    a = find(a), b = find(b);
    if (r[a] < r[b]) swap(a,b);
    p[b] = a;
    r[a] += r[b];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        cin>>n>>m>>k;
        edges.clear();

        forn(i,m) {
            ll u,v,s; cin>>u>>v>>s;
            edges.push_back({s,u,v});
        }

        for (int i = 1; i <= n; i++) {
            p[i] = i;
            r[i] = 1;
        }

        // Puedo hacer arbol por debajo de k?
        ll ans = 1e18;
        for (tuple<ll,ll,ll>& e : edges) {
            ll u, v, s;
            tie(s, u, v) = e;
            
            // Actualizo la respuesta por si si
            ans = min(ans, abs(s-k));
            // Dejo lista la arista por si no (para hacer mst con costos)
            e = {max(0LL,s-k), u, v};

            if (s <= k) unite(u,v);
        }

        bool conectados = true;
        int x = find(1);
        for (int i = 1; i <= n; i++) {
            if (find(i) != x) {
                conectados = false;
                break;
            }
        }
       
        if (conectados) {
            // Puedo hacer el arbol con aristas por debajo de k; meto al arbol la de menor costo
            cout<<ans<<"\n";
            continue;
        }

        // Hago MST de costos (no va a ser 0 porque llegue hasta aqui)
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            r[i] = 1;
        }

        sort(edges.begin(), edges.end());
        ans = 0;
        for (tuple<ll,ll,ll>& e : edges) {
            ll u, v, s;
            tie(s, u, v) = e;
            if (!same(u,v)) {
                unite(u,v);
                ans += s;
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
