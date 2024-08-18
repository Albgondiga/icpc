// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;
const ll INF=1e13+7;
#define debug 0
#define ifd if (debug)

bitset<100> seen[100][100];
vector<vector<vector<ll>>> dp(100, vector<vector<ll>> (100, vector<ll> (100)));
vector<int> m1(100), m2(100);

int n;

bool invalid(int x1, int x2) {
    return (x1*3>=50||x2*3>=50||3*(x1+x2)>=90);
}

ll f(ll i, ll x1, ll x2) {
    ifd cout<<"me estoy fijando en "<<i<<" "<<x1<<" "<<x2<<endl;
    if (invalid(x1, x2)) return -1*INF;
    if (i==n-1) {
        if (invalid(x1+m1[i], x2+m2[i])) return 0;
        else return 1;
    }

    if (seen[i][x1][x2]) return dp[i][x1][x2];
    seen[i][x1][x2]=true;

    dp[i][x1][x2] = max(f(i+1, x1, x2), 1+f(i+1, x1+m1[i], x2+m2[i]));
    return dp[i][x1][x2];
}




int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n;
    ll ans =80-n;
    ll trash;
    forn(i, n) 
        cin>>trash>>m1[i]>>m2[i];
    
    ans+=f(0, 0, 0);
    cout<<ans<<endl;
}
