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

#define debug 1
#define ifd if (debug)

const ll MOD = 1e9+7;
const ll N = 102;
vector<ll> factoriales(N);
vector<ll> inv(N);
bitset<1005> seen[1005];
vector<vector<ll> > dp(1005, vector<ll> (1005));
ll m;

ll f(ll p, ll i) {
    if (p==0) return 1;
    if (p<0) return 0;
    if (i==1) {
        if (p<=m) return 1;
        else return 0;
    }

    if (seen[p][i]) return dp[p][i];
    seen[p][i] =1;
    ll ans=0;
    for (int j=0; j<=m; j++) {
        ans+=f(p-j, i-1);
        ans%=MOD;
    }
    return dp[p][i]=ans;
}


ll exp(ll b, ll e) {
    ll r = 1;
    while (e) {
        if (e % 2) r = r*b % MOD;
        b = b*b % MOD;
        e /= 2; 
    }
    return r;
}

ll Binom(ll n, ll k) {
    if (k==0) return 1;
    return (factoriales[n] * inv[k] % MOD * inv[n-k] % MOD);
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n, p1, p2;
    cin>>n>>m>>p1>>p2;

    factoriales[0] = 1;
    for (ll i = 1; i < N; i++) {
        factoriales[i] = factoriales[i-1] * i % MOD;
    }

    inv[N-1] = exp(factoriales[N-1], MOD-2);
    for (ll i = N-2; i >= 0; i--) {
        inv[i] = inv[i+1] * (i+1) % MOD;
    }
    
    ll minP1=p1/m;
    ll minP2=p2/m;
    ll minP=min(minP1, minP2);
    ll otroMinP=max(minP1, minP2);

    ll ans=0;
    for (int i=minP1; n-i>=otroMinP; i++) {
        ll cA=Binom(n, i);
        ifd cout<<"vea que "<<n<<"escojo "<<i<<"="<<cA<<endl;
        cA%=MOD;
        ll f1=f(p1, i);
        ifd cout<<"vea que f("<<p1<<", "<<i<<") = "<<f1<<endl;

        cA*=f1;
        cA%=MOD;
        ll f2=f(p2, n-i);
        ifd cout<<"vea que f("<<p2<<", "<<n-i<<") = "<<f2<<endl;
        cA*=f2;
        cA%=MOD;
        ans+=cA;
        ans%=MOD;
    }


    cout<<ans<<endl;
    return 0;
}
