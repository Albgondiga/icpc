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

const int N = 100+1, V = 1e3;
const ll INF = 1e18;
int n;
ll w;
ll peso[N], val[N];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>w;
    for (int i = 1; i <= n; i++) 
        cin>>peso[i]>>val[i];

    // dp[i][v] tiene el min peso para obtener v usando los primeros i
    vector<vector<ll>> dp(n+1, vector<ll>(V+1,0));
    dp[0][0] = 0;
    for (int v = 1; v <= V; v++) dp[0][v] = INF;
    for (int i = 1; i <= n; i++) {
        for (int v = 0; v <= V; v++) {
            dp[i][v] = dp[i-1][v];
            if (v >= val[i] and dp[i-1][v-val[i]] < INF)  
                dp[i][v] = min(
                    dp[i-1][v],
                    dp[i-1][v-val[i]] + peso[i]
                );
        }
    }

    ll ans = 0;
    for (int v = 0; v <= V; v++) {
        if (dp[n][v] <= w) ans = v;
    }

    cout<<ans<<"\n";

    return 0;
}
