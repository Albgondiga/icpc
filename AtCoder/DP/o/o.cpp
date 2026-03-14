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

const int N = 21;
const ll MOD = 1e9+7;
int n;

int comp[N][N];
vector<ll> dp;

// f(mask) = formas de emparejar al hombre popcount(mask) 
// en adelante, usando las mujeres ya marcadas.
// mask tiene las mujeres emparejadas
int f(int mask) {
    // 10...0 - 1 = 11...1 <- n 1's
    if (mask == (1 << n) - 1) return 1;
    if (dp[mask] == -1) {
        // Hombre numero h
        int h = __builtin_popcount(mask);
        ll ans = 0;
        // Lo emparejo con todas las m posibles
        for (int m = 0; m < n; m++) {
            if (!(mask & (1 << m)) and comp[h][m]) {
                ans += f(mask | (1 << m));
                ans %= MOD;
            }
        }
        dp[mask] = ans;
    }
    return dp[mask];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // Bitmask
    cin>>n;
    forn(i,n) forn(j,n) cin>>comp[i][j];
    dp.assign(1<<n, -1);

    cout<<f(0)<<"\n";

    return 0;
}
