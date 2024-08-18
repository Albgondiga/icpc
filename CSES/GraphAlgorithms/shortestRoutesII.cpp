#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define pf push_front
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef pair<ll,ll> pll;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

const ll INF = 1e18;
const int N = 500+1;
int n, m, q;
ll dist[N][N];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;      
        }
    }
    forn(i,m) {
        ll a, b, c; cin>>a>>b>>c;
        dist[a][b] = dist[b][a] = min(c,dist[a][b]);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);   
            }
        }
    }

    while (q--) {
        int a, b; cin>>a>>b;
        if (dist[a][b] == INF) cout<<-1<<"\n";
        else cout<<dist[a][b]<<"\n";
    }

    return 0;
}
