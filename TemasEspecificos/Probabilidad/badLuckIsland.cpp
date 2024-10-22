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

// https://codeforces.com/problemset/problem/540/D

const int N = 101;
double dp[N][N][N];

double ganaR(int r, int s, int p) {
    if (r == 0) return dp[r][s][p] = 0.0;
    if (s == 0 and p > 0) return dp[r][s][p] = 0.0;
    if (p == 0) return dp[r][s][p] = 1.0;
    if (dp[r][s][p] == -1.0) {
        dp[r][s][p] = (double)(r*p)/(r*p+r*s+s*p)*ganaR(r-1,s,p);
        dp[r][s][p] += (double)(r*s)/(r*p+r*s+s*p)*ganaR(r,s-1,p);
        dp[r][s][p] += (double)(s*p)/(r*p+r*s+s*p)*ganaR(r,s,p-1);
    }
    return dp[r][s][p];
}

double ganaS(int r, int s, int p) {
    if (s == 0) return dp[r][s][p] = 0.0;
    if (p == 0 and r > 0) return dp[r][s][p] = 0.0;
    if (r == 0) return dp[r][s][p] = 1.0;
    if (dp[r][s][p] == -1.0) {
        dp[r][s][p] = (double)(r*p)/(r*p+r*s+s*p)*ganaS(r-1,s,p);
        dp[r][s][p] += (double)(r*s)/(r*p+r*s+s*p)*ganaS(r,s-1,p);
        dp[r][s][p] += (double)(s*p)/(r*p+r*s+s*p)*ganaS(r,s,p-1);
    }
    return dp[r][s][p];
}

double ganaP(int r, int s, int p) {
    if (p == 0) return  dp[r][s][p] = 0.0;
    if (r == 0 and s > 0) return dp[r][s][p] = 0.0;
    if (s == 0) return dp[r][s][p] = 1.0;
    if (dp[r][s][p] == -1.0) {
        dp[r][s][p] = (double)(r*p)/(r*p+r*s+s*p)*ganaP(r-1,s,p);
        dp[r][s][p] += (double)(r*s)/(r*p+r*s+s*p)*ganaP(r,s-1,p);
        dp[r][s][p] += (double)(s*p)/(r*p+r*s+s*p)*ganaP(r,s,p-1);
    }
    return dp[r][s][p];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int r, s, p; cin>>r>>s>>p;

    cout<<setprecision(9)<<fixed;
    forn(i,N) forn(j,N) forn(k,N) dp[i][j][k] = -1.0;
    cout<<ganaR(r,s,p)<<" ";
    forn(i,N) forn(j,N) forn(k,N) dp[i][j][k] = -1.0;
    cout<<ganaS(r,s,p)<<" ";
    forn(i,N) forn(j,N) forn(k,N) dp[i][j][k] = -1.0;
    cout<<ganaP(r,s,p)<<"\n";

    return 0;
}
