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

const ll MOD = 1e9+7;
const int N = 1e5+1;
vector<int> adj[N];
int n;
bool visited[N];
ll dp[N][2];

#define white 0
#define black 1

ll f(int v, int color) {
    if (dp[v][color] != -1) return dp[v][color];
    visited[v] = true;
    ll count = 1;
    for (int u : adj[v]) {
        if (!visited[u]) {
            count *= f(u, white);
            count %= MOD;
        }
    }
    return dp[v][color] = count;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    forn(i,n) {
        int x, y; cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        dp[i][white] = -1;
        dp[i][black] = -1;
    }   
    
    ll count = f(1, white);
    count += f(1, black);
    cout<<count<<"\n";

    return 0;
}
