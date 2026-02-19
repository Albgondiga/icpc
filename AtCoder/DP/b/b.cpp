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
const int N = 1e5;
int n, k;
ll h[N], dp[N];

ll f(int i) {
    if (i == n-1) return 0;
    if (dp[i] == -1) {
        if (i+1 < n) dp[i] = abs(h[i]-h[i+1])+f(i+1);
        for (int j = 1; j <= k; j++) 
            if (i+j < n) dp[i] = min(dp[i], abs(h[i]-h[i+j])+f(i+j));
    }
    return dp[i];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;
    forn(i,n) {
        cin>>h[i];
        dp[i] = -1;
    }

    f(0);
    
    cout<<dp[0]<<"\n";

    return 0;
}
