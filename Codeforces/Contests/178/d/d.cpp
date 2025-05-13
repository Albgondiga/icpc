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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<ll> primos, sieve(1e7+5,0);
    for (ll x = 2; x <= 1e7; x++) {
        if (sieve[x]) continue;
        primos.push_back(x);
        for (ll u = 2*x; u <= 1e7; u += x) {
            sieve[u] = x;
        }
    }

    ll t; cin>>t;
    while (t--) {
        ll n; cin>>n;
        vector<ll> v(n);
        for (ll& x : v) cin>>x;

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        ll miSuma = 0, sumaPrimos = 0;
        ll utiles = 0;
        for (ll i = 0; i < n; i++) {
            miSuma += v[i];
            sumaPrimos += primos[i];
            if (miSuma >= sumaPrimos) {
                utiles = i+1;
            }
        }
        cout<<n-utiles<<"\n";
    }

    return 0;
}
