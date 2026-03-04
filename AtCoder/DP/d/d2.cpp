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

const int N = 100+1;
int n;
ll w;
ll peso[N], val[N];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>w;
    for (int i = 1; i <= n; i++) 
        cin>>peso[i]>>val[i];

    // dp[i][j] tiene el max val usando los primeros i con peso maximo j
    vector<vector<ll>> dp(n+1, vector<ll>(w+1,0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (j < peso[i]) dp[i][j] = dp[i-1][j];
            else 
                dp[i][j] = max(
                    dp[i-1][j],
                    dp[i-1][j-peso[i]] + val[i]
                );
        }
    }

    cout<<dp[n][w]<<"\n";

    return 0;
}
