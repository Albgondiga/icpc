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

const ll MOD = 1e9+7;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k; cin>>n>>k;

    vector<ll> a(n+1);
    forn(i,n) cin>>a[i+1];

    // dp[i][j] tiene maneras de repartir j confites entre los primeros i ninos
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        // pSum de formas de repartir todas las cantidades de confites 
        // usando i-1 ninos
        vector<ll> pSum(k+1, 0);
        pSum[0] = dp[i-1][0];
        for (int j = 1; j<= k; j++) {
            pSum[j] = (pSum[j-1] + dp[i-1][j]) % MOD;
        }

        // dp[i][j] = dp[i-1][j]+dp[i-1][j-1]+...+dp[i-1][j-a[i]]
        for (int j = 0; j <= k; j++) {
            int l = j-a[i], r = j;
            // Esto tiene desde 0
            dp[i][j] = pSum[r];
            // Entonces quito lo que sobra
            // dp[i-1][l] + ... + dp[i-1][r]
            if (l-1 >= 0) 
                dp[i][j] = (dp[i][j] - pSum[l-1] + MOD) % MOD;
        }
    }

    cout<<dp[n][k]<<"\n";

    return 0;
}
