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

vector<int> a;
// dp[k] dice si el jugador en turno tiene estrategia ganadora con k piedra
vector<bool> dp, seen;

bool f(int k) {
    if (k == 0) return false;
    if (!seen[k]) {
        seen[k] = true;
        for (int x : a) {
            if (x > k) break;
            if (f(k-x) == false) {
                return dp[k] = true;
            }
        }
    }
    return dp[k];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k; cin>>n>>k;
    a.resize(n);
    forn(i,n) cin>>a[i];

    dp.assign(k+1, false), seen.assign(k+1, false) ;
    
    f(k);
    
    cout<<(dp[k] ? "First" : "Second")<<"\n";

    return 0;
}
