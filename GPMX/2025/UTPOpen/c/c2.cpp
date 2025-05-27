#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

const ll N = 1e6;
vector<ll> digitos(64,0LL);

int msb(ll x) {
    return 63 - __builtin_clzll(x);
}

ll pot(int k) {
    if (k == 0) return 1;
    return k * (1 << (k-1)) + 1;
}

ll contarUnos(ll x) {
    if (x == 0) return 0LL;
    int k = 0; 
    ll piso = 0, ans = 0; 
    while (x > 0) {
        k = msb(x);
        piso = (x & ~(1<<k));
        ans += (piso + pot(k));
        x = piso;
    }

    return ans;
}

ll contarDigitos(ll x) {
    if (x == 0) return 0LL;
    int k = msb(x);
    ll piso = x-(1<<k);
    ll ans = (k > 0 ? (digitos[k-1]+((piso+1)*(k+1))) : 1LL);
    return ans;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    digitos[0] = 1;
    for (int k = 1; k < 64; k++) {
        digitos[k] = digitos[k-1]+(pow(2LL,k)*(k+1));
    }

    int q; cin>>q;
    while (q--) {
        ll l, r; cin>>l>>r;
        l = max(0LL, l-1);
        ll countUnos = contarUnos(r)-contarUnos(l);
        ll countDigitos = contarDigitos(r)-contarDigitos(l);
        cout<<countUnos+countDigitos-r+l<<"\n";
    }

    return 0;
}
