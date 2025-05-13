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

    ll t; cin>>t;
    while (t--) {
        ll n; cin>>n;
        vector<ll> v(n), s(n), M(n), m(n);
        for (ll& x : v) 
            cin>>x;

        M[0] = v[0];
        for (ll i = 1; i < n; i++) 
            M[i] = max(v[i],M[i-1]);

        s[n-1] = m[n-1] = v[n-1];
        for (ll i = n-2; i >= 0; i--) {
            m[i] = min(v[i],m[i+1]);
            s[i] = v[i] + s[i+1];
        }

        for (int i = 1; i < n; i++) {
            if (v[n-i] < M[n-i-1]) {
                //ifd cout<<m[n-i]<<" es menor que "<<M[n-i-1]<<endl;
                cout<<(s[n-i]-v[n-i]+M[n-i-1])<<" ";
            } else {
                cout<<s[n-i]<<" ";
            }
        }
        cout<<s[0]<<"\n";
    }

    return 0;
}
