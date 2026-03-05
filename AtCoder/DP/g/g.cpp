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

const int N = 1e5+1;
vector<int> adj[N];
bool visited[N];
vector<int> topSort;

void dfs(int v) {
    if (visited[v]) return;
    visited[v] = true;

    for (int u : adj[v])
        dfs(u);

    topSort.push_back(v);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    forn(i,m) {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
    }

    for (int v = 1; v <= n; v++)
        if (!visited[v]) dfs(v);

    reverse(topSort.begin(), topSort.end());

    vector<int> dp(n+1,0);
    for (int u : topSort) {
        for (int v : adj[u]) {
            dp[v] = max(dp[v], dp[u]+1); 
        }
    }

    cout<<*max_element(dp.begin(), dp.end())<<"\n";

    return 0;
}
