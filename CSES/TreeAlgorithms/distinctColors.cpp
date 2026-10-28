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
set<int> s[N];
int ans[N];

// Small to large
void dfs(int u, int p = 0) {
    for (int c : adj[u]) {
        if (c == p) continue;
        dfs(c, u);
        if (s[c].size() > s[u].size()) swap(s[c], s[u]);
        for (int x : s[c]) s[u].insert(x);
    }
    ans[u] = s[u].size();
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    forn(i,n) {
        int col; cin>>col;
        s[i+1].insert(col);
    }
    forn(i,n-1) {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) cout<<ans[i]<<" ";
}
