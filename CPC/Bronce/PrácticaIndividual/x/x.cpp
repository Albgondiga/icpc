#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
const ll MOD = 10000007;

#define debug 1
#define ifd if (debug)

ll binpow(ll a, ll b, ll m) {
    if (b == 0) return 1;
    if (b % 2) return binpow(a,b-1,m) * a % m;
    ll res = binpow(a,b/2,m);
    return res * res % m;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    forn(i,t) {
        ll a,b;
        cin>>a>>b;
        cout<<binpow(a,b,10)<<"\n";
    }
}
