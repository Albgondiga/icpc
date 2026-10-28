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
const int INF = 1e9;
vector<int> adj[N];
int dp0[N], dp1[N];

void dfs(int u, int p = 0) {
    dp0[u] = 0, dp1[u] = -INF;   // imposible hasta encontrar un hijo
    for (int c : adj[u]) {
        if (c == p) continue;
        dfs(c, u);
        dp0[u] += max(dp0[c], dp1[c]);
    }
    // segunda pasada: ya conocemos dp0[u] completo
    for (int c : adj[u]) {
        if (c == p) continue;
        // dp0[u] - max(dp0[c], dp1[c]) = suma de max(dp0[d], dp1[d]) para todos los demas hijos d
        dp1[u] = max(dp1[u], dp0[u] - max(dp0[c], dp1[c]) + dp0[c] + 1);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    forn(i,n-1) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    cout << max(dp0[1], dp1[1]) << "\n";

    return 0;
}