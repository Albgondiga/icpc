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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

const int N = 2e5 + 1;
vector<int> adj[N];
// Diametro con tecnica del problema de rerooting
int f[N], h[N];
int diam = 0;

void dfs(int u, int p) {
    f[u] = h[u] = 0;
    for (int c : adj[u]) {
        if (c == p) continue;
        dfs(c, u);
        int dist = f[c] + 1;
        if (dist > f[u]) { 
            h[u] = f[u]; 
            f[u] = dist; 
        }
        else if (dist > h[u]) h[u] = dist;
    }
    diam = max(diam, f[u] + h[u]);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    cout << diam << "\n";

    return 0;
}