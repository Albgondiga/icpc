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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int r, c, q;
    while (cin>>r>>c>>q) {
        if (r == 0) return 0;
        vector<vector<int>> adj(r+1, vector<int>(r+1, 0));
        forn(i, c) {
            int a, b; cin>>a>>b;
            adj[a][b] = adj[b][a] = 1;
        }

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= r; j++) {
                if (adj[i][j]) {

                }
            }
        }

        while (q--) {
            int s, t; cin>>s>>t;
            if (adj[s][t] == 1) cout<<"Y\n";
            else cout<<"N\n";
        }
        cout<<"-\n";
    }

    return 0;
}
