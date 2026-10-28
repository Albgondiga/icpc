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

const int N = 2e5+1;
int n;
vector<int> adj[N];
int sz[N];

void dfs(int u, int p = 0) {
    sz[u] = 1;
    for (int c : adj[u]) {
        if (c == p) continue;
        dfs(c, u);
        sz[u] += sz[c];
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

	cin>>n;
	forn(i,n-1) {
		int p; cin>>p;
		adj[p].push_back(i+2);
		adj[i+2].push_back(p);
	}

    dfs(1);
    for (int i = 1; i <= n; i++) cout<<sz[i]-1<<" ";

    return 0;
}
