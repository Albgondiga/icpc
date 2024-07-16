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

#define debug 1
#define ifd if (debug)

const int INF = 1e6+5;
const int N = 500;
int dp[N][N][N+1];
int n, k;
string s;

int f(int i, int j, int k) {
    if (k > j-i+1) return INF;
    if (k <= 1) return 0;
    if (dp[i][j][k] == -1) {
        if (s[i]==s[j]) dp[i][j][k] = f(i+1,j-1,k-2);
        else dp[i][j][k] = min(f(i+1,j-1,k-2)+1, min(f(i+1,j,k), f(i,j-1,k)));
    }
    return dp[i][j][k];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>k>>s;
    forn(i,n) forn(j,n) forn(l,k+1) dp[i][j][l] = -1;

    cout<<f(0, n-1, k)<<"\n";

    return 0;
}