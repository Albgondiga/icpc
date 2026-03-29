#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define fst first
#define snd second
#define fore(e,c) for(const auto &e : (c))
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 0
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        int n; cin>>n;

        vector<ll> a(n);
        forn(i,n) cin>>a[i];
        forn(i,n) cin>>a[i];

        int ans = 0;
        forn(i,n) {
            ll x1 = ((i > 0) ? gcd(a[i-1], a[i]) : 1);
            ll x2 = ((i < n-1) ? gcd(a[i], a[i+1]) : 1);
            ll x = lcm(x1, x2);
            ifd cout<<"En i = "<<i<<", x1 = "<<x1<<", x2 = "<<x2<<", x = "<<x<<endl;
            while (x <= a[i]) {
                if (x != a[i]) {
                    ifd cout<<"Puedo cambiar "<<a[i]<<" por "<<x<<endl;
                    ans++;
                    break;
                }
                x += x;
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
