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

const int MAX = 5000+5;
string s1, s2;
int dp[MAX][MAX];


int fR(int n, int m) {
    if (n == 0) return m;
    if (m == 0) return n;

    if (dp[n][m] == -1) {
        dp[n][m] = min( fR(n-1,m-1) + (s1[n-1]==s2[m-1]? 0:1), min( fR(n-1,m)+1, fR(n,m-1)+1 ));
    }
    return dp[n][m];
}

int fI(int n, int m) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else dp[i][j] = min( dp[i-1][j-1]+(s1[i-1]==s2[j-1]? 0:1), min( dp[i-1][j]+1, dp[i][j-1]+1 ));
        }  
    }
    return dp[n][m];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>s1>>s2;
    int n = s1.length(), m = s2.length();   

    forn(i,n+1) forn(j,m+1) dp[i][j] = -1; 

    cout<<fR(n,m)<<"\n";
    ifd forn(i,n+1) { forn(j,m+1) cout<<dp[i][j]<<" "; cout<<"\n"; } 

    return 0;
}