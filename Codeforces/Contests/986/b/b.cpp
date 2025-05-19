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
        ll n, b, c; cin>>n>>b>>c;

        if (b == 0) {
            if (c == n-1 or c == n-2) cout<<n-1<<"\n";
            else if (c >= n) cout<<n<<"\n";
            else cout<<-1<<"\n";
            continue;
        }

        if (c >= n) {
            cout<<n<<"\n";
            continue;
        }
        // Primer i tal que b(i-1)+c >= n
        ll i = (n+b-c+1LL)/b;
        cout<<max(0LL,n-i+1)<<"\n";
    }

    return 0;
}
