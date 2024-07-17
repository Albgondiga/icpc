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

const ll MOD = 998244353;
const int MAX = 1e5+5;

ll dp[MAX];
vector<vector<int>> subs(MAX);

ll f(int n) {
    if (subs[n].size() == 0) dp[n] = 0;
    else if (dp[n] == -1) {
        ll res = 0;
        for (auto s : subs[n]) {
            res += f(s)+1;
            res %= MOD;
        }
        dp[n] = res;
    }
    return dp[n];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n, m; cin>>n>>m;
    forn(i,m) {
        ll a, b; cin>>a>>b;
        subs[a].push_back(b);
    }
    ifd {    
        for (int i = 1; i <= n; i++) {
            cout<<"Subs de "<<i<<": ";
            for (auto s : subs[i]) {
                cout<<s<<" ";
            }     
            cout<<"\n";
        }
    }

    forn(i,MAX) dp[i] = -1;

    cout<<f(1)<<"\n";
    ifd for (int i = 1; i <= n; i++) cout<<dp[i]<<" ";
    return 0;
}