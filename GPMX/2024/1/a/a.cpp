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
const int N = 1e4;
int dp[N][N];
int n, q;
string s;
vector<int> A;

int f(int l, int r) {
    if (r-l == 1) return abs(A[r]-A[l]);
    if (dp[l][r] == -1) {
        dp[l][r] = min(abs(A[r]-A[l]), min(f(l+1,r), f(l,r-1)));
    }
    return dp[l][r];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    A.resize(n);
    forn(i,n) cin>>A[i];
    cin>>q;
    forn(i,n) forn(j,n) dp[i][j] = -1;

    int l, r;
    while(q--) {
        cin>>l>>r;
        cout<<f(l-1,r-1)<<"\n";
    }

    return 0;
}
