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

const ll INF = 1e18;
int n;
vector<ll> a, p;
// dp[i][j] tiene el min costo de mergear l...r
vector<vector<ll>> dp;

ll f(int l, int r) {
    if (l == r) return 0;
    if (dp[l][r] == -1) {
        ll x = INF;
        for (int i = l; i < r; i++) {
            x = min(x, f(l,i) + f(i+1,r) + (p[r]-p[l-1]));
        }
        dp[l][r] = x;
    }
    return dp[l][r];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    a.resize(n+1), p.assign(n+1,0);
    forn(i,n) cin>>a[i+1];

    for (int i = 1; i <= n; i++) p[i] = p[i-1] + a[i];

    dp.assign(n+1, vector<ll>(n+1, -1));

    f(1,n);

    cout<<dp[1][n]<<"\n";

    return 0;
}
