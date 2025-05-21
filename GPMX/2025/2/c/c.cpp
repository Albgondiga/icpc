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

vector<ll> digitos(64,0LL);

int msb(ll x) {
    return 63 - __builtin_clzll(x);
}

ll pot(int k) {
    if (k == 0) return 1;
    return k * pow(2LL,k-1) + 1;
}

ll count(ll x) {
    if (x == 0) return 0LL;
    int k = msb(x);
    //ifd cout<<"x = "<<x<<", k = "<<k<<endl;
    ll piso = x-(1<<k);
    ll unos = (piso + pot(k) + count(piso));
    ll ans = unos + (k > 0 ? (digitos[k-1]+((piso+1)*(k+1))) : 1LL);
    ifd cout<<"k = "<<k<<endl;
    ifd cout<<"unos = "<<unos<<endl;
    ifd cout<<"digitos = "<<(k > 0 ? (digitos[k-1]+((piso+1)*(k+1))) : 1LL)<<endl;
    ifd cout<<"x = "<<x<<" retorna "<<ans-x<<endl;
    return ans;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    digitos[0] = 1;
    for (int k = 1; k < 64; k++) {
        digitos[k] = digitos[k-1]+(pow(2LL,k)*(k+1));
        //ifd cout<<"digitos["<<k<<"] = "<<digitos[k]<<endl;
    }

    int q; cin>>q;
    while (q--) {
        ll l, r; cin>>l>>r;
        ifd cout<<"NUEVO CASO"<<endl;
        //ifd cout<<"count(r) = "<<count(r)<<", count(l-1) = "<<count(max(l-1,0LL))<<endl;
        cout<<count(r)-count(max(l-1,0LL))-r+max(0LL,l-1)<<"\n";
        ifd cout<<endl;
    }

    return 0;
}
