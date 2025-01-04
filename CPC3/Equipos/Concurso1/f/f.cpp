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
const int MAXN=100100;

#define debug 0
#define ifd if (debug)

ll n, m, a, b, c;
string s, t;

const int MAX = 2*1e3+5;
ll dp[MAX][MAX];

ll cost(int i, int j) {
    if (s[i]==t[j]) return 0;
    return min(c, a+b);
}

ll fR(int n, int m) {
    if (n == 0) return m*a;
    if (m == 0) return n*b;

    if (dp[n][m] == -1) {
        dp[n][m] = min( fR(n-1,m-1)+cost(n-1,m-1), ll(min( fR(n-1,m)+b, fR(n,m-1)+a )));
    }
    return dp[n][m];
}

ll fI(int n, int m) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0) dp[i][j] = j*a;
            else if (j == 0) dp[i][j] = i*b;
            else dp[i][j] = min( dp[i-1][j-1]+cost(i-1,j-1), min( dp[i-1][j]+b, dp[i][j-1]+a ));
        }  
    }
    return dp[n][m];
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>a>>b>>c;
    cin>>s>>t;

    forn(i,n+1) forn(j,m+1) dp[i][j] = -1;

    cout<<fR(n,m)<<"\n";
    ifd forn(i,n+1) { forn(j,m+1) cout<<dp[i][j]<<" "; cout<<"\n"; } 

    return 0;
}   