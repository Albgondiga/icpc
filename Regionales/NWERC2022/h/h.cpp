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

// https://codeforces.com/gym/104875

vector<vector<int>> adj;
// maxDepth[v] es la profundidad maxima empezando en v
vector<int> maxDepth, target;

// Calculo niveles
void dfs1(int v, int p = 0) {
    maxDepth[v] = 1;
    for (int& u : adj[v]) {
        if (u == p) continue;
        dfs1(u,v);
        maxDepth[v] = max(maxDepth[v], maxDepth[u]+1);
    }
}

// Calculo targets
void dfs2(int v, int p = 0, int hermano = -1) {
    if (v != 1) {
        // Target es minimo entre mi nivel, el nivel del otro hijo + 1, o el target de mi papa -1
        target[v] = min(target[p]-1, min(maxDepth[v], (hermano == -1 ? 1 : maxDepth[hermano]+1)));
    }
    int n1 = -1, n2 = -1;
    for (int& u : adj[v]) {
        if (u == p) continue;
        if (n1 == -1) n1 = u;
        else if (n2 == -1) n2 = u;
    }
    if (n1 != -1) {
        dfs2(n1, v, n2);
        if (v != 1) target[v] = target[n1]+1;
    }
    if (n2 != -1) {
        dfs2(n2, v, n1);
        if (v != 1) target[v] = max(target[n1], target[n2]+1);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    adj.resize(n+1), maxDepth.resize(n+1), target.resize(n+1);
    for (int i = 0; i < n; i++) {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1);
    target[1] = maxDepth[1];
    dfs2(1);
    int ans = 0;
    for (int i = 1; i <= n; i++) if (target[i] <= 0) ans++;
    cout<<ans<<"\n";

    return 0;
}
