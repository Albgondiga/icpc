// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;

#define debug 1
#define ifd if (debug)

// https://codeforces.com/group/6V7amHIf8K/contest/725221/problem/J

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<ll> w(n+1);
    forn(i, n) cin >> w[i+1];
    vector<vector<int>> adj(n+1);
    forn(i, n-1) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS desde la raíz: padres y orden (padres antes que hijos, por niveles)
    vector<int> par(n+1, 0), orden;
    vector<bool> vis(n+1, false);
    orden.push_back(1); vis[1] = true;
    forn(i, n) {
        int x = orden[i];
        for (int y : adj[x]) {
            if (!vis[y]) {
                vis[y] = true;
                par[y] = x;
                orden.push_back(y);
            }
        }
    }

    // leer todas las operaciones
    vector<int> op(m), val(m);
    vector<int> distinctA;
    vector<bool> seenA(n+1, false);
    forn(t, m) {
        cin>>op[t]>>val[t];
        if (op[t] == 1 and !seenA[val[t]]) {
            seenA[val[t]] = true;
            distinctA.push_back(val[t]);
        }
    }

    // valos agregado por operacion
    vector<ll> delta(m, 0);
    // lca[u] = lca(v, u) para todo u
    vector<int> lca(n+1);
    // onPath[v] me dice si el nodo esta en el camino desde la raiz hasta v
    vector<char> onPath(n+1, 0);

    for (int v : distinctA) {
        for (int y = v; y != 0; y = par[y]) onPath[y] = 1;
        for (int u : orden) lca[u] = (onPath[u] ? u : lca[par[u]]);
        for (int y = v; y != 0; y = par[y]) onPath[y] = 0;

        // barrer las operaciones en orden
        // frecuencia de v en A, suma de w_lca(v,b) contando todos los b hasta el momento
        ll freqV = 0, suma = 0;
        forn(t, m) {
            if (op[t] == 1) {
                if (val[t] == v) {
                    delta[t] += suma;
                    freqV++;
                }
            } else {
                ll x = w[lca[val[t]]];
                delta[t] += freqV * x;
                suma += x;
            }
        }
    }

    ll ans = 0;
    forn(t, m) {
        ans += delta[t];
        cout << ans << "\n";
    }
    return 0;
}