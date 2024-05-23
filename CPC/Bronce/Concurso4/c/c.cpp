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
typedef pair<ll,ll> pll;
typedef pair<string, int> si;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 1
#define ifd if (debug)

ll binpow(ll a, ll b, ll m) {
    if (b == 0) return 1;
    if (b % 2) return binpow(a,b-1,m) * a % m;
    ll res = binpow(a,b/2,m);
    return res * res % m;
}

ll primeFactorsMCD(ll n, ll p)  {
    ll mcd = 1;
    ll count = 0;
    bool d = false;
    while (p % 2 == 0) { 
        count++;
        d = true;
        p = p/2; 
    } 
    if (d) mcd *= binpow(2,count/n,100000007);
    for (ll d = 3; d <= sqrt(p); d+=2) { 
        count = 0;
        d = false;
        while (p % d == 0) {
            count++;
            d = true;
            p = p/d; 
        }
        if (d) mcd *= binpow(d,count/n,100000007);
    } 
    // if (p > 1) 
    //     mcd *= binpow(n,count/n,100000007);
    return mcd;
} 

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll N, P; cin>>N>>P;
    cout<<primeFactorsMCD(N,P)<<endl;
}