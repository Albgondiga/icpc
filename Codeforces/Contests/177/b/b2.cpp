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

    int t; cin>>t;
    while (t--) {
        ll n, k, x; cin>>n>>k>>x;
        vector<ll> v(n);
        for (ll& a : v) cin>>a;

        vector<ll> s(n);
        s[n-1] = v[n-1];
        for (ll i = n-2; i >= 0; i--) s[i] = v[i]+s[i+1];

        ll mult = 0;
        if (s[0] < x) {
            mult = x/s[0];
            if (x % s[0]) mult++;

            if (mult >= 0 and mult <= k) {
                s[0] *= mult;
                for (ll i = 1; i < n; i++) {
                    s[i] = s[i-1]-v[i-1];
                }
            } else {
                cout<<0<<"\n";
                continue;
            }
        }        

        ll count = max((mult-1),0LL) * n;
        for (ll i = n-1; i >= 0; i--) {
            if (s[i] >= x) break;
            count++;
        }
        
        cout<<(n*k - count)<<"\n";
    }

    return 0;
}
