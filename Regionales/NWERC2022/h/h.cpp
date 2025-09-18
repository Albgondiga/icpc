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

vector<vector<int>> adj;
// maxDepth[v] es la profundidad maxima empezando en v
vector<ll> maxDepth;
int n;
int ans = 0;

void dfs1(int v, int p = 0) {
    maxDepth[v] = 1;
    for (int& u : adj[v]) {
        if (u == p) continue;
        dfs1(u,v);
        maxDepth[v] = max(maxDepth[v], maxDepth[u]+1);
    }
}

void dfs2(int v, int p = 0) {

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    adj.resize(n+1), maxDepth.resize(n+1);
    for (int i = 0; i < n; i++) {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1);
    //for (int i = 1; i <= n; i++) cout<<i<<": "<<maxDepth[i]<<endl;
    cout<<ans<<"\n";

    return 0;
}
