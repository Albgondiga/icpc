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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    vector<ll> a(n);
    forn(i,n) cin>>a[i];

    // dp[l][r] tiene max X-Y para el jugador en turno
    // o sea, la mejor diferencia posible (mis puntos - puntos del otro)
    vector<vector<ll>> dp(n, vector<ll>(n));

    // Computo los intervalos por tamano
    forn(i,n) dp[i][i] = a[i];
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + (len-1) < n; l++) {
            int r = l+(len-1);
            dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
        }
    }

    cout<<dp[0][n-1]<<"\n";

    return 0;
}
