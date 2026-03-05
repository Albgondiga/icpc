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

int n;
vector<double> p;
// dp[i][k] probabilidad de tener k heads empezando en la moneda i
vector<vector<double>> dp;

double f(int i, int k) {
    if (k < 0) return 0.0;
    if (i == n) return (k == 0 ? 1.0 : 0.0);
    if (dp[i][k] == -1.0) {
        dp[i][k] = (1.0 - p[i]) * f(i+1, k) + p[i] * f(i+1, k-1);
    }
    return dp[i][k];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    p.resize(n);
    forn(i,n) cin>>p[i];

    dp.assign(n+1, vector<double>(n+1,-1.0));
    
    double ans = 0.0;
    for (int k = n/2+1; k <= n; k++) ans += f(0,k);

    cout<<setprecision(10)<<fixed<<ans<<"\n";

    return 0;
}
