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

const int N = 1e5;
int n;
ll points[N][3], dp[N][3];

ll f(int i, int type) {
    if (i == n-1) dp[i][type] = points[i][type];
    if (dp[i][type] == -1) {
        ll x = points[i][type];
        forn(j,3) {
            if (j == type) continue;
            dp[i][type] = max(dp[i][type], x + f(i+1, j));
        }
    }
    return dp[i][type];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    forn(i,n) forn(j,3) {
        cin>>points[i][j];
        dp[i][j] = -1;
    }

    forn(i,3) f(0,i);

    cout<<max(dp[0][0], max(dp[0][1], dp[0][2]))<<"\n";

    return 0;
}
