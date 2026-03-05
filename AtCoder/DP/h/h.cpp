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
const int N = 1000+1;
int n, m;
char v[N][N];
ll dp[N][N];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin>>v[i][j];

    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((i == 1 and j == 1) or v[i][j] == '#') continue;
            if (i > 1) dp[i][j] += dp[i-1][j];
            dp[i][j] %= MOD;
            if (j > 1) dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }

    cout<<dp[n][m]<<"\n";

    return 0;
}
