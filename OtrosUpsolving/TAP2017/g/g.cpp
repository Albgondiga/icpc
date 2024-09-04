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

#define debug 1
#define ifd if (debug)

const ll MOD = 1e9+7;
const ll MAXN = 105;
const ll MAXP = 1005;
vector<ll> factoriales(MAXN);
vector<ll> inv(MAXN);
ll dp[MAXN][MAXP];
ll m, p1, p2;

ll exp(ll b, ll e) {
    ll r = 1;
    while (e) {
        if (e % 2) r = (r*b) % MOD;
        b = (b*b) % MOD;
        e /= 2; 
    }
    return r;
}

ll Binom(ll n, ll k) {
    if (k == 0) return 1;
    return (((factoriales[n] * inv[k]) % MOD * inv[n-k]) % MOD);
}

// Numero de maneras de hacer j puntos en i rondas, haciendo
// entre 1 y M puntos en cada una
ll f(ll i, ll j) {
    if (j < 0) return 0;
    if (i == 0) {
        if (j == 0) return 1;
        else return 0; 
    }

    if (dp[i][j] == -1) {
        ll ans = 0;
        for (ll p = 1; p <= m; p++) {
            ans += f(i-1, j-p);
            ans %= MOD;
        }  
        dp[i][j] = ans;
    }
    return dp[i][j];
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n;
    cin>>n>>m>>p1>>p2;

    factoriales[0] = 1;
    for (ll i = 1; i < MAXN; i++) {
        factoriales[i] = (factoriales[i-1] * i) % MOD;
    }

    inv[MAXN-1] = exp(factoriales[MAXN-1], MOD-2);
    for (ll i = MAXN-2; i >= 0; i--) {
        inv[i] = (inv[i+1] * (i+1)) % MOD;
    }

    forn(i, MAXN) forn(j, MAXP) dp[i][j] = -1;

    ll ans = 0;
    for (ll i = 1; i < n; i++) {
        for (ll j = 1; j <= n-i; j++) {
            ll x = 1;
            x *= f(i,p1); x %= MOD;
            x *= f(j,p2); x %= MOD;
            x *= Binom(n,i); x %= MOD;
            x *= Binom(n-i,j); x %= MOD;
            ans += x;
        }
    }

    cout<<ans<<"\n";
    return 0;
}
