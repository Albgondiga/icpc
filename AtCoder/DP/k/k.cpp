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

    int n, k; cin>>n>>k;
    vector<int> a(n);
    forn(i,n) cin>>a[i];

    // dp[k] dice si el jugador en turno tiene estrategia ganadora con k piedras
    vector<bool> dp(k+1, false);
    
    for (int i = 1; i <= k; i++) {
        for (int x : a) {
            if (x > i) break;
            // Si hay un x tal que el otro no puede ganar con i-x, entonces gano en i
            if (dp[i-x] == false) {
                dp[i] = true;
                break;
            }
        }
    }

    cout<<(dp[k] ? "First" : "Second")<<"\n";

    return 0;
}
