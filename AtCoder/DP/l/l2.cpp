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

vector<ll> a;
// dp[l][r] tiene max X-Y para el jugador en turno
// o sea, la mejor diferencia posible (mis puntos - puntos del otro)
vector<vector<ll>> dp;

ll f(int l, int r) {
    if (l == r) return dp[l][r] = a[l];
    if (dp[l][r] == -1) {
        dp[l][r] = max(a[l]-f(l+1,r), a[r]-f(l,r-1));
    }
    return dp[l][r];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    a.resize(n);
    forn(i,n) cin>>a[i];

    dp.assign(n, vector<ll>(n, -1));

    f(0,n-1);

    cout<<dp[0][n-1]<<"\n";

    return 0;
}
