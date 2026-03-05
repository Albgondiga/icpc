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
    vector<double> p(n+1);
    forn(i,n) cin>>p[i+1];

    // Parecido a knapsack
    // dp[k] es la probabilidad de obtener k heads
    vector<double> dp(n+1, 0.0);
    dp[0] = 1.0;

    // Considero la moneda i con probabilidad pi de ser heads
    for (int i = 1; i <= n; i++) {
        double pi = p[i];
        // Calculo la probabilidad de que haya 0...i heads hasta esa moneda i
        for (int k = i; k >= 0; k--) {
            // Me sale tails
            double p1 = dp[k] * (1.0 - pi);
            // Me sale heads
            double p2 = (k > 0 ? dp[k-1] * pi : 0.0);
            dp[k] = p1 + p2;
        }
    }

    double ans = 0.0;
    for (int k = n/2+1; k <= n; k++) ans += dp[k];

    cout<<setprecision(10)<<fixed<<ans<<"\n";

    return 0;
}
