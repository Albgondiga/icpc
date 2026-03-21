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

vector<vector<int>> adj;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        int n, m; cin>>n>>m;
        adj.assign(n+1, vector<int>());
        forn(i,m) {
            int u, v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Revisar
		vector<int> color(n+1, -1);
		int ans = 0;
		forn(i, n) if (color[i+1] == -1) {
			queue<int> q;
			q.push(i+1);
			color[i+1] = 0;
			vector<int> tamano(2);
			bool bipartito = true;
			while (!q.empty()){
				int v = q.front();
				q.pop();
				++tamano[color[v]];
				for (int u : adj[v]){
					if (color[u] == color[v])
						bipartito = false;
					else if (color[u] == -1){
						color[u] = color[v] ^ 1;
						q.push(u);
					}
				}
			}
			if (bipartito) ans += max(tamano[0], tamano[1]);
		}
		cout<<ans<<'\n';
	}
    return 0;
}
