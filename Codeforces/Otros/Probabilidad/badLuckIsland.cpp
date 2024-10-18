#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define pf push_front
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef pair<ll,ll> pll;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

const int N = 101;
double dp[N][N][N];

// Gana r
double f1(int r, int s, int p) {
    ifd cout<<"r = "<<r<<", s = "<<s<<", p = "<<p<<endl;
    if (r == 0) return dp[r][s][p] = 0;
    if (s == 0 and p > 0) return dp[r][s][p] = 0;
    if (p == 0) return dp[r][s][p] = 1;
    if (dp[r][s][p] == -1) {
        dp[r][s][p] = 1/3*f1(r-1,s,p) + 1/3*f1(r,s-1,p) + 1/3*f1(r,s,p-1);
    }
    return dp[r][s][p];
}
// Gana s
double f2(int r, int s, int p) {
    if (s == 0) return dp[r][s][p] = 0;
    if (p == 0 and r > 0) return dp[r][s][p] = 0;
    if (r == 0) return dp[r][s][p] = 1;
    if (dp[r][s][p] == -1) {
        dp[r][s][p] = 1/3*f2(r-1,s,p) + 1/3*f2(r,s-1,p) + 1/3*f2(r,s,p-1);
    }
    return dp[r][s][p];
}
// Gana p
double f3(int r, int s, int p) {
    if (p == 0) return  dp[r][s][p] = 0;
    if (r == 0 and s > 0) return dp[r][s][p] = 0;
    if (s == 0) return dp[r][s][p] = 1;
    if (dp[r][s][p] == -1) {
        dp[r][s][p] = 1/3*f3(r-1,s,p) + 1/3*f3(r,s-1,p) + 1/3*f3(r,s,p-1);
    }
    return dp[r][s][p];
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int r, s, p; cin>>r>>s>>p;

    cout<<setprecision(9)<<fixed;
    forn(i,N) forn(j,N) forn(k,N) dp[i][j][k] = -1;
    cout<<f1(r,s,p)<<" ";
    forn(i,N) forn(j,N) forn(k,N) dp[i][j][k] = -1;
    cout<<f2(r,s,p)<<" ";
    forn(i,N) forn(j,N) forn(k,N) dp[i][j][k] = -1;
    cout<<f3(r,s,p)<<"\n";

    return 0;
}
