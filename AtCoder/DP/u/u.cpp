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

const int N = 16;
const ll INF = 1e18;
int n;
ll a[N][N];
vector<ll> dp, pts;

ll f(int mask) {
    if (mask == 0) return 0;
    if (dp[mask] == -1) {
        ll ans = -INF;
        // Fijo un conejo con el bit menos significativo para no repetir
        // Ejemplo evitar hacer {A,B},{C} y {C},{A,B}
        int conejo = __builtin_ctz(mask);
        // Hago todos los subgrupos bajando hasta cero dejandome los conejos 
        // iniciales
        for (int submask = mask; submask; submask = (submask - 1) & mask) {
            if (submask & (1 << conejo)) {
                ans = max(ans, pts[submask] + f(mask ^ submask));
            }
        }
        dp[mask] = ans;
    }
    return dp[mask];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    forn(i,n) forn(j,n) cin>>a[i][j];

    int M = 1<<n;
    pts.assign(M, 0);
    // Precalculo los puntos de cada grupo
    forn(mask, M) {
        ll sum = 0;
        forn(i,n) {
            if (!(mask & (1<<i))) continue;
            // Sumo todos los pares para ese conejo
            for (int j = i+1; j < n; j++) {
                if (mask & (1 << j)) {
                    sum += a[i][j];
                }
            }
        }
        pts[mask] = sum;
    }

    dp.assign(M, -1);
    cout<<f(M-1)<<"\n";

    return 0;
}
