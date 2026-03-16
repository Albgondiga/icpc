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
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

vector<int> p, nodos, aristas;

int find(int a) {
    if (p[a] != a) p[a] = find(p[a]);
    return p[a];
}

bool same(int a, int b) { 
    return (find(a) == find(b));
}

void unite(int a, int b) {
    if (same(a,b)) return;
    a = find(a), b = find(b);
    if (nodos[a] < nodos[b]) swap(a,b);
    p[b] = p[a];
    nodos[a] += nodos[b];
    aristas[a] += (aristas[b]+1);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        int n, m; cin>>n>>m;

        vector<ii> edges;
        forn(i,m) {
            int u, v; cin>>u>>v;
            edges.push_back({u,v});
        }

        p.resize(n+1), nodos.resize(n+1), aristas.resize(n+1);
        for (int i = 1; i <= n; i++) {
            p[i] = i, aristas[i] = 0, nodos[i] = 1;
        }
        for (const ii& e : edges) {
            int a = e.first, b = e.second;
            if (same(a,b)) {
                aristas[find(a)]++;
            }
            unite(a,b);
        }

        set<int> papas;
        for (int i = 1; i <= n; i++) {
            papas.insert(find(i));
        }

        int ans = 0;
        for (int i : papas) {
            if (nodos[i] == 1) ans++;
            else if (aristas[i] % 2) ans += nodos[i]/2; 
        }

        cout<<ans<<"\n";
    }

    return 0;
}
