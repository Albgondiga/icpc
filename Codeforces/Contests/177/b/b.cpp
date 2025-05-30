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

        ll count = 0;
        vector<ll> s(n);
        s[0] = v[0];
        ll l = 0, r = 1;
        if (s[0] >= x) count = l = 1;
        while (r < n) {
            s[r] = v[r]+s[r-1];
            if (s[r]-(l == 0 ? 0 : s[l-1]) >= x) {
                count++;
                l++;
            }
            r++;
        }
        count *= k;
        if (k > 1) count *= (k-1);
        cout<<count<<"\n";
    }

    return 0;
}
