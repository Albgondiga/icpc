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
typedef pair<string, int> si;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXn=100100;

#define MOD 1000000

#define debug 0
#define ifd if (debug)

ll binpow(ll a, ll b, ll m) {
    if (b == 0)
        return 1;

    if (b % 2)
        return binpow(a, b-1, m) * a % m;

    ll res = binpow(a, b/2, m);
    return res*res % m;
}

ll getDigit(ll k){
    if (k <= 9)
        return k;

    ll len = 1;
    while(9 * binpow(len-1, 10, MOD) * len < k-1){
        k -= 9 * binpow(len-1, 10, MOD) * len;
        len++;
    }

    ll value = binpow(len-1, 10, MOD) + k-1/len - 1;
    ifd cout<<"len == "<<len<<endl;
    ifd cout<<"value == "<<value<<endl;
    return value / (binpow(10, (value % len)+1, MOD));
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll q; cin>>q;
    for (ll i = 0; i < q; i++) {
        ll k; cin>>k;
        cout<<getDigit(k)<<"\n";
    }

    return 0;
}
